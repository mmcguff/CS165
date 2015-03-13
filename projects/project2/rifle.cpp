//#include <cassert>
#include <cstdlib>

#include "rifle.h"
#include "uiDraw.h"



/**********************************************************************
 * Description: 
**********************************************************************/
Rifle::Rifle() : angle(90)
{
   // initilizing the bullets in an array
   try
   {
      bullets = new Bullet[NUM_BULLETS];
   }
   catch(std::bad_alloc)
   {
      // exit
   }
}


/**********************************************************************
 * Description: 
**********************************************************************/
void Rifle::fire()
{
   std::cerr << "FIRE!!!!!!!!!!!\n";
   for (short i = 0; i < NUM_BULLETS; ++i)
      if(!bullets[i].getIsDead()) // if it is dead we can fire it
      {
         // shoot it
         bullets[i].fire(angle);
         // stop shooting
         i = NUM_BULLETS;
      }
}

/**********************************************************************
 * Description: 
**********************************************************************/
void Rifle::moveBullets()
{
   for (short i = 0; i < NUM_BULLETS; ++i)
      if(bullets[i].getIsDead()) // if it is dead we can fire it
      {
         // cheking if bullet when out of the screen
         bullets[i].isDead();
         // shoot it
         bullets[i].advance();
         // stop shooting
      }
}

/**************************************************
 * MOVE
 * Moves the rifle according to user input
 * INPUT: left - the number of presses of the left arrow
 * right - the number of presses of the right arrow
 * OUTPUT: (Rifle moves left or right accordingly)
 ***************************************************/
void Rifle::move(int up, int down)
{
   //User pressing down arrow?
   if (down)
      angle -= down;  
   //User pressing up arrow?
   if (up)
      angle += up;
   //Make sure the rifle stays in its place
   if (angle < 0)
      angle = 0;
   if (angle > 90)
      angle = 90;
   return;
}
/****************************************************
 * DRAW
 * Draws the rectangle representing the rifle to the screen
 * INPUT: -
 * OUTPUT: -
 ****************************************************/
void Rifle::draw()
{
   //Point object for rifle position
   Point pt = new Point();
   //The rifle is in the bottom right corner
   pt.setX(pt.getXMax());
   pt.setY(pt.getYMin());
   drawRect(pt, RIFLE_WIDTH, RIFLE_HEIGHT, 90 - this->angle);

   // drawing bullets to the screen
   for (short i = 0; i < NUM_BULLETS; ++i)
      if (bullets[i].getIsDead())
         bullets[i].draw();
   return;
}
