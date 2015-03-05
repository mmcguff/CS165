/***********************************************************************
* Program:
*    Assignment 11, GetCoordinate()           
*    Brother Sloan, CS165
* Author:
*    Larry Dewey
* Summary: 
*    This program was designed to obtain two coordinates from one user
*    making sure that they cannot input invalid information.
* 
*
*    Estimated:  ? hrs   
*    Actual:     0.5 hrs
************************************************************************/

#include <iostream>
using namespace std;

/************************************************************************
 * GET COORDINATES
 * Prompt the user for a row and column
 ************************************************************************/
void getCoordinates(int &col, int &row)
{
   bool done = false;

   cout << "Please enter a row and column where both are integers\n";

   do
   {
      cout << "> ";
      cin >> col;
      cin >> row;
   
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
         cout << "ERROR: non-digit entered\n";
      }
      else
      {
         done = true;
      }

   }while (!done);

}

/***********************************************************************
 * Simple driver program for getCoordinates
 ************************************************************************/
int main()
{
   int col;
   int row;
  
   getCoordinates(col, row);
  
   cout << "The values are: ("
        << col << ", " << row << ")\n";
   return 0;
}
