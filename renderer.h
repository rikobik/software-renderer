#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "2d_draw.h"

class Renderer
{
 public:
  sf::Image convertImage(draw::Image);
  void run();
  void setImage(draw::Image);
  draw::Image getImage();
  Renderer(int width, int height);

 private:
  draw::Image m_currentImage;
  int m_height, m_width;
};



#endif
