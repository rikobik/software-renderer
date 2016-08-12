#include "2d_draw.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace draw;

Image::Image(int width, int height): m_height(height), m_width(width) 
{
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
        {
            m_data.push_back(Pixel());
        }
}

void Image::setPixelAt(int width, int height, const Pixel &pixel)
{
  m_data[m_width * height + width] = {pixel.red, pixel.green, pixel.blue, pixel.alpha};
}

Pixel Image::getPixelAt(int width, int height)
{
  Pixel p =  m_data[m_width * height + width];
  return {p.red, p.green, p.blue, p.alpha};
}

void draw::drawLine(Image &img, const Point2D &p1, const Point2D &p2, const Color &color)
{
  int x0 = p1.x, x1 = p2.x, y0 = p1.y, y1 = p2.y;
  bool steep = false;
  if (std::abs(p1.x - p2.x) < std::abs(p1.y - p2.y)) {
      x0 = p1.y;
      x1 = p2.y;
      steep = true;
    }
  if (x0 > x1)
    {
      std::swap(x0, x1);
      std::swap(y0, y1);
    }
  int dx = x1 - x0;
  int dy = y1 - y0;
  int derror2 = std::abs(dy) * 2;
  int error2 = 0;
  int y = y0;
  for(int x = x0; x <= x1; x++) {
    if(steep) {
      img.setPixelAt(y, x, {255, 0, 0, 255});
    }
    else { 
      img.setPixelAt(x, y, color);
    }
    error2 += derror2;
    if (error2 > dx) {
      y += (y1 > y0 ? 1 : -1);
      error2 -= dx * 2;
    }
  }
}

  void draw::fillTriangle(const Point2D &p1, const Point2D &p2, const Point2D &p3)
  {
    
  }
  


