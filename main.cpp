#include "Scene.h"

int main()
{
  // INITIALISE OBJECTS
  Scene scene;

  // GAME LOOP
  while(scene.running())
  {
    // EVENT LOOP: poll events, switch events' types, ...
    scene.update();
    // RENDERING LOOP: window.clear(), draw() and display()
    scene.render();
  }

  return 0;
}