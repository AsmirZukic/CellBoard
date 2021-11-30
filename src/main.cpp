#include "../include/engine.h"
#include "../include/board.hpp"

int main( int argc, char* argv[] )
{
  Engine engine;
  int w, h;

  SDL_GetWindowSize( Window::getInstance()->getWindow(), &w, &h);
  Board board( w, h);

  while( engine.isRunning() )
  {
    engine.render();
    board.render();
    board.update( w, h );
    engine.draw();
  }
}
