#pragma once
#include "renderer.hpp"
#include "inputHandler.hpp"

class Engine
{
private:
  bool running = false;

public:
  Engine();

  ~Engine();

  virtual void render();

  const bool isRunning();

  void draw();

};
