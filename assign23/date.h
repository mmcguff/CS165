/***********************************************************************
* Program:
*    Assignment 22, Basic Date Class
*    Brother Sloan, CS165
* Author:
*    Larry Dewey
* Summary:
*    This is a driver program for a simple date class.  Your job is
*    to write date.h and date.cpp.  This file is to remain untouched.
************************************************************************/

#ifndef DATE_H
#define DATE_H

#include <iostream>   // for COUT, CIN, CERR
#include <cassert>    // for ASSERT
#include <cstdlib>    // for EXIT
#include <string>     // for strings
#include <error.h>    // for cerr
using namespace std;

class Date
{
   public:
      int getYear(){return year;};
      int getMonth(){return month;};
      int getDay(){return day;};
      void initialize();
      void uninitialize();
      bool setDate(int year, int month, int day);
      bool setYear(int year){this->year = year; return true;};
      bool setMonth(int month){this->month = month; return true;};
      bool setDay(int day){this->day = day; return true;};
      void displayLong();
   private:
      int day, month, year;
      void assertDate();
      int daysMonth(int month, int year);
      bool isLeapYear(int year);
   protected:
};

#endif // DATE_H
