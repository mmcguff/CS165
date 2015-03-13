/***********************************************************************
 * Program:
 *    Skeet. What?  you never heard of skeet?
 * Author:
 *    Br. Helfrich
 * Summary:
 *    OK, I couldn't help myself.  The first video game is "Tennis for Two"
 *    developed in 1958 (you read that correctly) by William Higinbotham
 *    as a demo for the computer systems in the Brookhaven National Laboratory.
 *    The display was a normal oscilloscope.  Ours will use slighly more
 *    advanced graphics: OpenGL
 ***********************************************************************/

#include "point.h"       // the ball has a position
#include "uiInteract.h"  // interface with OpenGL
#include "uiDraw.h"      // all the draw primitives exist her
#include <cstdlib> // for ramdom gravity
#include <ctime> // for ramdom time
#include "bird.h"
#include "rifle.h"

// size of the paddle
//#define PADDLE 40

// set the bounds of the game
float Point::xMin = -200.0;
float Point::xMax =  200.0;
float Point::yMin = -200.0;
float Point::yMax =  200.0;

/*****************************************
 * SKEET
 * The main skeet structure containing everything
 * necessary to plan our beloved game
 ****************************************/
class Skeet
{
public:
   Skeet();                          // set up the game
   void advance();                  // advance the game by one move
   void draw();                     // draw everything
   void move(int up, int down, int space);     // move everything
   void hit();                   // did we hit something?
private:
   Bird bird;
   Point possitionScore;        // just so we don't create every time
   Point possitionMissed;
   bool dead;    // is the game over?
   int score;    // current score.. how many times did we hit the ball?
   // Rifle
   Rifle rifle;
   int missed;
};

/***************************************************
 * SKEET :: CONSTRUCTOR
 * Give the ball a random vertical velocity and set
 * the positions of everything else.
 ***************************************************/
Skeet::Skeet() : rifle(), bird(), dead(false), score(0), missed(0)
{
   Point temp;
   possitionScore.setX(temp.getXMin() + 5);
   possitionScore.setY(temp.getYMax() - 5);
   possitionMissed.setX(temp.getXMax() - 50);
   possitionMissed.setY(temp.getYMax() - 5);
};

/********************************************
 * SKEET :: ADVANCE
 * Move the ball forward by some amount
 *******************************************/
void Skeet::advance()
{
   // calling bird to do this job
   bird.advance();
   
   if(bird.isDead())
      missed++;

   // we need to move the bullets
   rifle.moveBullets();

}

/****************************************
 * STRIKE
 * Strike the paddle.  The further from the center,
 * the more it hits
 ****************************************/
void Skeet::hit()
{
   for (int i = 0; i < NUM_BULLETS; ++i)
   {
      // we don't want to check a bullet if it's not alive
      if (rifle.getBullet(i).getIsDead())
      {
         double distance = sqrt(pow(rifle.getBullet(i).getVelocity().getPoint().getX() -
                                    bird.getVelocity().getPoint().getX(), 2) +
                                pow(rifle.getBullet(i).getVelocity().getPoint().getY() -
                                    bird.getVelocity().getPoint().getY(), 2));
         if (distance < bird.getRadius())
         {
            bird.kill();
            
            rifle.getBullet(i).kill();
            score += 5;
         }
      }
   }

}

/**************************************************
 * SKEET : MOVE
 * Move the paddle
 *************************************************/
void Skeet::move(int up, int down, int space)
{
   // moving the rifle at request
   rifle.move(up, down);

   // shooting at request
   if (space)
      rifle.fire();
}

/*************************************************
 * SKEET : DRAW
 * Draw the stuff
 ************************************************/
void Skeet::draw()
{

   // draw rifle and bullets
   rifle.draw();

   if (bird.getIsDead())
      bird.draw();

   // draw score
   drawNumber(possitionScore, score);

   // draw missed score
   drawNumber(possitionMissed, missed);
   
}

/*********************************************
 * CALLBACK
 * The main interaction loop of the engine.
 * This gets called from OpenGL.  It give us our
 * interface pointer (where we get our events from)
 * as well as a void pointer which we know is our
 * game class.
 *********************************************/
void callBack(const Interface *pUI, void *p)
{
   // we know the void pointer is our game class so
   // cast it into the game class.
   Skeet *pSkeet = (Skeet *)p;

   // advance the ball
   pSkeet->advance();

   // check the paddle
   pSkeet->move(pUI->isUp(), pUI->isDown(), pUI->isSpace());

   // did we hit the bird?
   pSkeet->hit();

   // draw it
   pSkeet->draw();
}


/*********************************
 * MAIN
 * initialize the drawing window, initialize
 * the game,and run it!
 *********************************/
int main(int argc, char **argv)
{
   srand(time(NULL));
   // Start the drawing
   Interface ui(argc, argv, "Skeet!");

   // play the game.  Our function callback will get called periodically
   Skeet skeet;  
   ui.run(callBack, (void *)&skeet);

   return 0;
}
