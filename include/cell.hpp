#pragma once
#include <SDL2/SDL.h>

class Cell
{
private:
  int xPos, yPos, mWidth, mHeight;
  bool mAlive = true;

public:
  SDL_Rect cell;
  Cell();
  Cell( int xPos, int yPos, int width, int height);
  ~Cell();

  const SDL_Rect& getCell() { return cell; }
  const bool isAlive() { return mAlive; }
  const int getXPos(){ return xPos; }
  const int getYPos(){ return yPos; }

  void makeAlive();
  void makeDead();
};
