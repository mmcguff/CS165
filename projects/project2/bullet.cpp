#include "bullet.h"
#include <stdlib.h>
#include <cmath>

#define ABS(value) ((value > 0)? value : value * -1) 
/**********************************************************************
 * Description: 
**********************************************************************/
Bullet::Bullet() : alive(false)
{
   // put the bullet outside of the screem while they are not shoot
   velocity.setPointX(velocity.getPoint().getXMax() + 1);

   velocity.setPointY(velocity.getPoint().getYMin() - 1);

   velocity.setDy(0);
   velocity.setDx(0);
}

/**********************************************************************
 *
 ***********************************************************************/
Bullet & Bullet::operator = (const Bullet & rhs)
{
   velocity.setPointX(rhs.velocity.getPoint().getX());

   velocity.setPointY(rhs.velocity.getPoint().getY());

   velocity.setDy(rhs.getVelocity().getDy());
   velocity.setDx(rhs.getVelocity().getDx());
   
   return *this;

}

/**********************************************************************
 * get fire from press of space bar.  
 **********************************************************************/
void Bullet::fire(int angle)
{
   std::cerr << "In Bullet fire\n" << angle << std::endl;
   alive = true;


   float x = (velocity.getPoint().getXMax() -
              (MAGNITUDE_RIFLE * cos(deg2rad(angle))));
   float y = ((MAGNITUDE_RIFLE * sin(deg2rad(angle))) + 
              velocity.getPoint().getYMin()); 
              

   std::cerr << "yMin " << velocity.getPoint().getYMin() << std::endl;
   std::cerr << "yMin " << velocity.getPoint().getXMax() << std::endl;

//   std::cerr << "mag Y " << rad2deg(MAGNITUDE_RIFLE * sin(angle)) << std::endl;
   
   std::cerr << "y " << y << std::endl;
   std::cerr << "x " << x << std::endl;
   velocity.setPointX(x);
   velocity.setPointY(y);
   
   velocity.setDy((ABS((ABS(y) + velocity.getPoint().getYMin()))) / 10);
   velocity.setDx((ABS(x) - velocity.getPoint().getXMax()) / 10);

   return;   
}

/**********************************************************************
 * drawing the bird 
**********************************************************************/
void Bullet::draw()
{
   drawDot(velocity.getPoint());
}

/**********************************************************************
 * Description: 
**********************************************************************/
void Bullet::advance()
{
   // does it get it from velocity?
   // 10 is the constant velocity of bullets
   velocity.addPointX(velocity.getDx());
   velocity.addPointY(velocity.getDy());
}

/**********************************************************************
 * Description: 
**********************************************************************/
void Bullet::kill()
{
   alive = false;
   
   // placing bullet at end of rifle
   velocity.setPointX(velocity.getPoint().getXMax() + 1);

   // casting point to int for angle of rifle
   velocity.setPointY(velocity.getPoint().getYMin() - 1);

   velocity.setDy(0);
   velocity.setDx(0);

   return;   
}

/**********************************************************************
 * Description: 
**********************************************************************/
void Bullet::isDead()
{
    // checking x first
   if (velocity.getPoint().getX() > velocity.getPoint().getXMax() ||
       velocity.getPoint().getX() < velocity.getPoint().getXMin())
      this->kill();

   // check Y 
   if (velocity.getPoint().getY() > velocity.getPoint().getYMax() ||
       velocity.getPoint().getY() < velocity.getPoint().getYMin())
      this->kill();
}
