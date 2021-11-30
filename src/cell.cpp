#include "../include/cell.hpp"

Cell::Cell() = default;

Cell::Cell(int xPos, int yPos, int width, int height ) : xPos( xPos ), yPos( yPos ), mWidth( width ), mHeight( height )
{
  cell = { xPos, yPos, width, height };
}

Cell::~Cell(){}

void Cell::makeAlive()
{
  if( mAlive == false )
    mAlive = true;
}

void Cell::makeDead()
{
  if( mAlive == true )
    mAlive = false;
}
