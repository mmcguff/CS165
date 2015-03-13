#ifndef BIRD_H
#define BIRD_H
#include "velocity.h" // need it for the class
#include "uiDraw.h"

#define NORMAL_BIRD 10
#define IN_SCREEN -1
#define SECOND 30
class Bird
{
  public:
   Bird(int rad = NORMAL_BIRD);                         // default contstructor
   void regenerate();              //make a new bird
   void draw();                    // draw the bird
   void advance();                 // move the bird
   bool getIsDead() const {return alive; }; // check if the bird is dead
   bool kill();                    // Kills the bird (resets to nothing)
   Velocity getVelocity() const { return velocity; }
   int  getRadius()       const { return radius; }   
   bool isDead();
   ~Bird() {};
   
  private:
   Velocity velocity;   // just velocity
   bool alive;        // dead bird check
   int radius;
   int time;
};

#endif
