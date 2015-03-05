/***********************************************************************
* Program:
*    Assignment 16, Rounding
*    Brother Sloan, CS165
* Author:
*    Larry Dewey
* Summary: 
*    This program is designed to round numbers. We will round
*    up, round down, and round depending on the value.
*
*    Estimated:  0.0 hrs   
*    Actual:     1.5 hrs
*      The hardest part of this program was handling the standard round.
************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

// round down always
float roundDown(float value);

// round up or down, depending...
float round(float value);

// round up always
float roundUp(float value);

/**********************************************************************
 * MAIN
 * Just a simple program to test three functions.
 ***********************************************************************/
int main()
{
   // fetch the value;
   float value;
   cout << "Please enter a value: ";
   cin  >> value;

   // configure the output for 2 decimal points of precision
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(2);

   // display the results
   cout << "Round down: " << roundDown(value) << endl;
   cout << "Round:      " << round(value)     << endl;
   cout << "Round up:   " << roundUp(value)   << endl;
   
   return 0;
}

/**********************************
 * roundDown (value) makes sure that the
 * decimal always rounds down to
 * the lowest integer.
 **********************************/
float roundDown(float value)
{
   return floor (value);
}

/**********************************
 * round(value) rounds the number up
 * if the floating point variable is
 * above or equal to 0.5. If it is
 * below, it will round down.
 **********************************/
float round(float value)
{
   int num = (int)value;
   float diff = value - num;
   if (diff >= 0.5)
   {
      num += 1;
      return num;
   }
   else
      return num;
}

/**********************************
 * roundUp rounds the number up
 * regardless of what the decimal
 * point is.
 **********************************/
float roundUp(float value)
{
   return ceil (value);
}
