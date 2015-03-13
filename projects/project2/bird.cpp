#include "bird.h" //need the header file
#include "point.h"  // use it for directoin
#include "bullet.h"
#include "uiDraw.h"

/**********************************************************************
 * Description: 
**********************************************************************/
Bird::Bird(int rad) : radius(rad)
{
   alive = true;
   // placing the bird on screen far left side
   velocity.setPointX(velocity.getPoint().getXMin());
   
   // casting point to int for rand (function min are floats)      
   int y = random(velocity.getPoint().getYMin(),
                velocity.getPoint().getYMax());
   velocity.setPointY(y);
   
   // if the position of y is lower screen then it will go up
   if(y <= 0)
   {
      // because the professor said so
      velocity.setDy(random(0, 4));
   }
   // if the position of y is upper screen then it will go down
   else
   {
      velocity.setDy(-(random(1, 3)));
   }
   
   // getting the speed
   velocity.setDx(random(3, 6));
}

/**********************************************************************
 * Regenerating the bird 
 **********************************************************************/
void Bird::regenerate() 
{
   alive = true;
   time = IN_SCREEN;
   
   // placing the bird on screen far left side
   velocity.setPointX(velocity.getPoint().getXMin() + radius);
   
   // casting point to int for rand (function min are floats)      
   int y = random(velocity.getPoint().getYMin() - radius,
                velocity.getPoint().getYMax()) + radius;
   velocity.setPointY(y);
   
   // if the position of y is lower screen then it will go up
   if(y <= 0)
   {
      // because the professor said so
      velocity.setDy(random(0, 4));
   }
   // if the position of y is upper screen then it will go down
   else
   {
      velocity.setDy(-(random(1, 3)));
   }
   
   // getting the speed
   velocity.setDx(random(3, 6));
}

/**********************************************************************
 * drawing the bird 
**********************************************************************/
void Bird::draw()
{
   drawCircle(velocity.getPoint(), radius, 12, 0);
}

/**********************************************************************
 * Description: 
**********************************************************************/
void Bird::advance()
{
   // arc is here
   velocity.addPointX(velocity.getDx());
   velocity.addPointY(velocity.getDy());
}

/**********************************************************************
 * Description: 
**********************************************************************/
bool Bird::kill()
{
   alive = false;
   time = 0;
   // placing the bird on screen far left side
   velocity.setPointX(velocity.getPoint().getXMin() - radius);
   velocity.setPointY(velocity.getPoint().getYMin() - radius);
   
   velocity.setDy(0);
   velocity.setDx(0);
   
}

/**********************************************************************
 * Description: 
**********************************************************************/
bool Bird::isDead()
{
   if (velocity.getPoint().getX() > velocity.getPoint().getXMax() + radius)
   {
      time++;
      // when outside of the screen
      if (time >= random(0, SECOND))
      {
         this->regenerate();
         return true; // the user missed the bird
      }
   }
   else
   {
      if (time >= 0)
         time++;
      // when shoot at with a bullet
      if (time >= random(0, SECOND))
      {
         this->regenerate();
         return false; // meaning the user did kill it
      }
      
   }
}
