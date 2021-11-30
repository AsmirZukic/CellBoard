#pragma once
#include "cell.hpp"
#include <vector>

class Board
{
private:
  int cellWidth, cellHeight;
  std::vector<Cell*> board;

public:
  Board();
  Board( int screenWidth, int screenHeight);
  ~Board();

  void render();
  void update( int screenWidth, int screenHeight );
};
