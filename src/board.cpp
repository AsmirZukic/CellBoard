#include "../include/board.hpp"
#include "../include/engine.h"
#include "../include/inputHandler.hpp"
#include "../include/vector2D.hpp"
#include <iostream>

Board::Board() = default;

Board::Board( int screenWidth, int screenHeight )
{
  cellWidth =  25;
  cellHeight = 25;

  for( auto y = 5; y <= screenHeight; y+= cellHeight + 5 )
  {
    for( auto x = 5; x <= screenWidth; x+= cellWidth + 5 )
    {
        board.push_back( new Cell( x, y, cellWidth, cellHeight ) );
    }
  }

}

Board::~Board()
{
  for( auto &it: board )
  {
    delete it;
  }
}

void Board::render()
{
  for( auto &it: board )
  {
    if( it->isAlive() )
    {
      SDL_SetRenderDrawColor( Renderer::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF );
    }
    else
    {
      SDL_SetRenderDrawColor( Renderer::getInstance()->getRenderer(), 0x0, 0x00, 0x00, 0xFF );
    }

    SDL_RenderFillRect( Renderer::getInstance()->getRenderer(), &it->getCell() );
  }
}

void Board::update( int screenWidth, int screenHeight )
{
  Vector2D* mousePos = InputHandler::getInstance()->getMousePos();

  for( auto &it : board )
  {
    //Mouse control
    if( mousePos->getX() >= it->getXPos() && mousePos->getX() <= ( it->getXPos() + cellWidth ) && mousePos->getY() >= it->getYPos() && mousePos->getY() <= ( it->getYPos() + cellHeight ) )
    {
        if( InputHandler::getInstance()->getMouseButtonState( 0 ) )
        {
            it->makeAlive();
        }
        if( InputHandler::getInstance()->getMouseButtonState( 2 ) )
        {
            it->makeDead();
        }
    }

  }

}
