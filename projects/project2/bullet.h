#ifndef BULLET_H
#define BULLET_H
#include "velocity.h"
#include "uiDraw.h"

#define MAGNITUDE_RIFLE 40
#define SPEED 10

/**********************************************************************
 * Description: 
**********************************************************************/
class Bullet
{
  public:
   Bullet();          // default constructor
   void fire(int angle);       // make new bullet
   void draw();       // draw the bullet
   void advance();    // move bullet
   // allows me to set the bullet back to live
   inline void setAlive() {alive = true; }
   
   inline bool getIsDead() const {return alive;  }; //check if bullet is dead
   void kill();       // kills bullet (reset for next fire)
                      // below is needed to get values from velocity 
   inline Velocity getVelocity() const { return velocity; } 
   void isDead();     //call to check value of alive
   ~Bullet() {};
   Bullet & operator = (const Bullet & rhs);   
  private:
   Velocity velocity; // just velocity
   bool alive;        // dead bullet check
   
};

#endif
