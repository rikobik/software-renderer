#include "renderer.h"
#include "2d_draw.h"

using namespace draw;

int main(int argc, char *argv[])
{
  Image img(1024, 768);
  drawLine(img, {10, 20}, {100, 200}, {255, 0, 0});
  Renderer renderer(1024, 768);
  renderer.setImage(img);

  renderer.run();
  
  return 0;
}

