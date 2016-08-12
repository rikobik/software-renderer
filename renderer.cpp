#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "2d_draw.h"
#include "renderer.h"

using namespace sf;
using namespace std;

Renderer::Renderer(int width, int height): m_width(width), m_height(height),
					   m_currentImage(width, height){};

void Renderer::setImage(draw::Image image)
{
  m_currentImage = image;
}

draw::Image Renderer::getImage()
{
  return m_currentImage;
}


Image Renderer::convertImage(draw::Image img)
{
  Image image;
  image.create(img.getWidth(), img.getHeight());
  for (int h = 0; h < img.getHeight(); h++)
    {
      for(int w = 0; w < img.getWidth(); w++)
	{
	  draw::Pixel p = img.getPixelAt(w, h);
	  Color c(p.red, p.green, p.blue, p.alpha);
	  image.setPixel(w, h, c);
	}
    }
  return image;
}

void Renderer::run()
{
    RenderWindow window;
    window.create(VideoMode(m_width, m_height), "software renderer");
    window.setFramerateLimit(60);
    Sprite sprite;
    Texture texture;
    while (window.isOpen())
    {
      Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == Event::Closed)
	    {
	      window.close();
	    }
	}
        window.clear(Color::Black);
	Image image = convertImage(m_currentImage);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();
    }
}

