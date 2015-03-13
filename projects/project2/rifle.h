#ifndef RIFLE_H
#define RIFLE_H
#include "point.h"
#include "bullet.h"

#define RIFLE_WIDTH 8
#define RIFLE_HEIGHT 80
#define NUM_BULLETS 5

class Rifle
{
  public:
   //Constructor
  Rifle();
  ~Rifle() {};
  void draw();
  void move(int up, int down);
  const int getAngle() const { return angle; };
  void fire();
  void moveBullets();
  Bullet &getBullet(int index) const {return bullets[index]; }
  private:
  int angle;
  // Rifle should have bullets not the game
  //Bullet bullet[NUM_BULLETS];
  Bullet *bullets;
};
#endif


