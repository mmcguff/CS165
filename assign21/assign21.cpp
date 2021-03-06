/***********************************************************************
* Program:
*    Assignment 21, Building a Class
*    Brother Sloan, CS165
* Author:
*    Larry Dewey
* Summary:
*    This program will demonstrate the implementation of a class
*    based on two procedural tools: pointers to functions, and structures.
*
*    Your job is to implement two functions referenced here:
*        display()  - from /home/cs165/date/date.cpp - displayShort()
*        set()      - from /home/cs165/date/date.cpp - setDate()
*    Estimated:  0.0 hrs
*    Actual:     2.0 hrs
*      The hardest thing for me on this project was realizing that I
*      needed to prototype the functions after declaring them in the
*      struct. I am so used to classes removing the need to prototype.
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/****************************************
 * DATE
 *  Our home-made class.  You are not allowed
 *  to change the definition of Date in any way
 ***************************************/
struct Date
{
   int year;
   int month;
   int day;
   void (*display)(const Date *pThis);
   bool (*set)(Date *pThis, int year, int month, int day);
   int (*daysMonth)(const Date *pThis, int month, int year);
   bool (*isLeapYear)(const Date *pThis, int year);
};

void display(const Date *pThis);
bool set(Date *pThis, int year, int month, int day);
int daysMonth(const Date *pThis, int month, int year);
bool isLeapYear(const Date *pThis, int year);

/**********************************************************************
 * MAIN is designed to use our home-made class called Date.  You are not
 *   allowed to change the definition of Date nor modify any code in MAIN
 ***********************************************************************/
int main()
{
   // Set up the structure.  Note how we have to manually
   // need to specify the member functions
   Date date;
   date.set     = &set;
   date.display = &display;

   // Get the user data
   int year;
   cout << "Year:  ";
   cin  >> year;

   int month;
   cout << "Month: ";
   cin  >> month;

   int day;
   cout << "Day:   ";
   cin  >> day;

   // Once we have specified the member functions, we call
   // them the way one would expect.
   date.set(    &date, year, month, day);
   date.display(&date);
   cout << endl;

   return 0;
}

/*********************************************************
 * SET DATE.  Set all 3 fields of the date type and doing error checking
 *   INPUT  day    Day between 1 and 31 (or 28, depending)
 *          month  Month between 1 and 12
 *          year   After 1753, before something crazy
 *   OUTPUT date   The newly formed type
 *          return Success?
 **********************************************************/
bool set(Date *pThis, int year, int month, int day)
{
   // validation
   if (year < 1753 || year > 2500)
      return false;
   if (month < 1 || month > 12)
      return false;
   if (day < 1 || day > daysMonth(pThis, month, year))
      return false;

   // assignment
   pThis->year = year;
   pThis->month = month;
   pThis->day = day;

   return true;
}

/**********************************************
 * DISPLAY SHORT.  Display the current date: 1/3/2010
 *  INPUT date   the current date
 *********************************************/
void display(const Date *pThis)
{
   cout << pThis->month << "/" << pThis->day << "/" << pThis->year;
}

/*****************************************************
 * DAYS MONTH.  How many days are there in the current month?
 *   INPUT  month    the month we are inquiring about
 *          year     we only care about this when month == 2
 *   OUTPUT return   return the number
 *****************************************************/
int daysMonth(const Date *pThis, int month, int year)
{
   if (month > 12 || month < 1)
   {
      assert(false);
      return 0;
   }

   const int DAYS[13] =
       /* JAN FEB MAR APR MAY JUN JUL AUG SEP OCT NOV DEC */
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // special case the one leap month
   if (month == 2 && isLeapYear(pThis, year))
      return 29;

   assert(month > 0 && month < 13);
   return DAYS[month];
}

/***********************************************
 * IS LEAP YEAR.  Is the passed year a leap year?
 *   INPUT   year    The current year
 *   OUTPUT  return  True if we are in a leap year
 **********************************************/
bool isLeapYear(const Date *pThis, int year)
{
   // no leap years before 1753
   assert(year >= 1753);

   // what, are you Buck Rogers?
   assert(year < 2500);

   // Not a leap year if not evenly divisible by 4
   // This will eliminate 75% of all years
   if (year % 4 != 0)
      return false; // 2001, 2002, 2003, 2005, etc.
   assert(year % 4 == 0);

   // Is a leap year if not divisible by 100
   // This will eliminate 96% of the rest
   if (year % 100 != 0)
      return true; // 1996, 2004, 2008, 2012, etc.
   // We better be 1800, 1900, 2000, 2100 at this point
   assert(year % 100 == 0);

   // Is a leap year if on the quad century
   if (year % 400 == 0)
      return true; // 1600, 2000, 2400, etc.
   // It better be something like 1800, 1900, 2100, etc.
   assert(year % 400 != 0);

   // the balance better be 1900, 1800, etc.
   assert(year == 1800 || year == 1900 || year == 2100 || year == 2200);
   return false;
}
