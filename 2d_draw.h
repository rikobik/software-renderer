#ifndef _2D_DRAW_H
#define _2D_DRAW_H

#include <vector>

namespace draw
{
 
struct Pixel
{
  int red = 0;
  int green = 0;
  int blue = 0;
  int alpha = 255;
};

typedef Pixel Color;
 
struct Point2D
{
  int x = 0;
  int y = 0;
};
 
class Image
{
private:
  std::vector<Pixel> m_data;
  unsigned int m_width;
  unsigned int m_height;
 public:
   Image(int width, int height);
   Pixel getPixelAt(int width, int height);
   void setPixelAt(int width, int height, const Pixel &pixel);
   int getWidth() { return m_width; };
   int getHeight() { return m_height; };
};


 void drawLine(draw::Image &img, const draw::Point2D &p1, const draw::Point2D &p2, const Color &color);

void fillTriangle(const Point2D &p1, const Point2D &p2, const Point2D &p3);

} // end namespace draw
 
#endif
