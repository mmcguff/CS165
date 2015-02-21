/***********************************************************************
* Program:
*    Assignment 26, The Gauntlet
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

      /********************
       * Constructors:
       ********************/
      // Default Constructor
      Date();

      // Non-Default Constructor 3 Inputs
      Date(int year, int month, int day);

      // Needed for addition and subtraction.
      Date(int year, int month, int day, int postfix);

      // Non-Default Constructor 1 Input
      Date (int year);

      // Destructor
      ~Date();

      /**************************
       * Overloaded Operators
       **************************/
      // Insertion and Extraction Operators
      friend inline ostream & operator << (ostream & out, const Date & rhs);
      friend inline istream & operator >> (ostream & out, Date & rhs);

      /*
      // Arithmetic Operators
      inline Date operator + (const Date & lhs, const Date & rhs);
      inline Date operator + (const Date & lhs, const int number);
      inline Date operator + (const int number, const Date & rhs);
      inline Date operator - (const Date & lhs, const Date & rhs);
      inline Date operator - (const Date & lhs, const int number);
      inline Date operator - (const int number, const Date & rhs);
      inline Date operator * (const Date & lhs, const Date & rhs);
      inline Date operator * (const Date & lhs, const int number);
      inline Date operator * (const int number, const Date & rhs);
      inline Date operator / (const Date & lhs, const Date & rhs);
      inline Date operator / (const Date & lhs, const int number);
      inline Date operator / (const int number, const Date & rhs);

      // Add-onto Operators
      inline Date & operator += (Date & lhs, const Date & rhs);
      inline Date & operator += (Date & lhs, const int number);
      inline Date & operator -= (Date & lhs, const Date & rhs);
      inline Date & operator -= (Date & lhs, const int number);
      inline Date & operator *= (Date & lhs, const Date & rhs);
      inline Date & operator *= (Date & lhs, const int number);
      inline Date & operator /= (Date & lhs, const Date & rhs);
      inline Date & operator /= (Date & lhs, const int number);

      // Increment and Decrement Operators
      inline Complex & operator ++ (Complex & lhs);
      inline Complex & operator -- (Complex & lhs);
      inline Complex operator ++ (Complex & rhs, int postfix);
      inline Complex operator -- (Complex & rhs, int postfix);

      // Negative and Not Operators
      inline Date operator - (const Date & rhs);
      inline bool operator ! (const Date & rhs);

      // Comparison Operators
      inline bool operator == (const Complex & lhs, const Complex & rhs);
      inline bool operator != (const Complex & lhs, const Complex & rhs);
      inline bool operator > (const Complex & lhs, const Complex & rhs);
      inline bool operator >= (const Complex & lhs, const Complex & rhs);
      inline bool operator < (const Complex & lhs, const Complex & rhs);
      inline bool operator <= (const Complex & lhs, const Complex & rhs);
      */

      /**************************
       * Getters and Setters
       **************************/
      // Getters
      inline int getYear() const
      {
         return year;
      };

      inline int getMonth() const
      {
         return month;
      };

      inline int getDay() const
      {
         return day;
      };

      int getDaysLeft() const;

      // Setters
      inline bool setYear(int year)
      {
         return (this->year = year);
      };

      inline bool setMonth(int month)
      {
         return (this->month = month);
      };

      inline bool setDay(int day)
      {
         return (this->day = day);
      };

      inline bool setShort()
      {
        return (isShort = true);
      };

      inline void initialize()
      {
         day = 1;
         month = 1;
         year = 2000;
      };

      void uninitialize();
      bool setDate(int year, int month, int day);
      void display() const;
      void displayShort() const;
      void displayLong() const;
      int postfix;

   private:
      void assertDate() const;
      static bool isShort;
      int day, month, year;
      int daysMonth(const int month, const int year) const;
      bool isLeapYear(const int year) const;
};

// Insertion and Extraction Operators
inline ostream & operator << (ostream & out, const Date & rhs)
{
   if (rhs.postfix == 1)
   {
      int tempDays = rhs.getDaysLeft() + (rhs.getYear() * 365);
      out << tempDays;

      return out;
   }

   if (!rhs.isShort)
   {
      rhs.assertDate();
      // day
      out << rhs.getDay();
      switch (rhs.getDay())
      {
         case 1:
         case 21:
         case 31:
            out << "st";
            break;
         case 2:
         case 22:
            out << "nd";
            break;
         case 3:
         case 23:
            out << "rd";
            break;
         default:
            out << "th";
      }

      // month
      const char MONTHS[12][10] =
         { "January", "February", "March",     "April",   "May",      "June",
           "July",    "August",   "September", "October", "November", "December"};

      out << " of " << MONTHS[rhs.getMonth() - 1] << ", ";

      // year
      out << rhs.getYear();

      return out;
   }
   else
   {
      rhs.assertDate();
      out << rhs.getMonth() << "/" << rhs.getDay() << "/" << rhs.getYear();

      return out;
   }
}

inline istream & operator >> (istream & in, Date & rhs)
{
   int day;
   int month;
   int year;

   in >> day >> month >> year;
   rhs.setDate(year, month, day);
   return in;
}

// Mathematics Operators
inline Date operator + (const Date & lhs, const Date & rhs)
{
   return Date(lhs.getYear() + rhs.getYear(),
           lhs.getMonth() + lhs.getMonth(),
           lhs.getDay() + lhs.getDay());
}

inline Date operator + (const Date & lhs, const int number)
{
   return Date(lhs.getYear(),
           lhs.getMonth(),
           lhs.getDay() + number);
}

inline Date operator + (const int number, const Date & rhs)
{
   return Date(rhs.getYear(),
           rhs.getMonth(),
           number + rhs.getDay());
}

inline Date operator - (const Date & lhs, const Date & rhs)
{

   return Date(lhs.getYear() - rhs.getYear(),
           lhs.getMonth() - rhs.getMonth(),
           lhs.getDay() - rhs.getDay(), 1);
}

inline Date operator - (const Date & lhs, const int number)
{
   return Date(lhs.getYear(),
           lhs.getMonth(),
           lhs.getDay() - number);
}

inline Date operator - (const int number, const Date & rhs)
{
   return Date(rhs.getYear(),
           rhs.getMonth(),
           number - rhs.getDay());
}

inline Date operator * (const Date & lhs, const Date & rhs)
{
   return Date(lhs.getYear() * rhs.getYear(),
           lhs.getMonth() * rhs.getMonth(),
           lhs.getDay() * rhs.getDay());
}

inline Date operator * (const Date & lhs, const int number)
{
   return Date(lhs.getYear(),
           lhs.getMonth(),
           lhs.getDay() * number);
}

inline Date operator * (const int number, const Date & rhs)
{
   return Date(rhs.getYear(),
           rhs.getMonth(),
           number * rhs.getDay());
}

inline Date operator / (const Date & lhs, const Date & rhs)
{
   return Date(lhs.getYear() / rhs.getYear(),
           lhs.getMonth() / rhs.getMonth(),
           lhs.getDay() / rhs.getDay());
}

inline Date operator / (const Date & lhs, const int number)
{
   return Date(lhs.getYear(),
           lhs.getMonth(),
           lhs.getDay() / number);
}

inline Date operator / (const int number, const Date & rhs)
{
   return Date(rhs.getYear(),
           rhs.getMonth(),
           number / rhs.getDay());
}

// Add-onto Operators
inline Date & operator += (Date & lhs, const Date & rhs)
{
   lhs.setDate(lhs.getYear() + rhs.getYear(),
               lhs.getMonth() + rhs.getMonth(),
               lhs.getDay() + rhs.getDay());

   return lhs;
}

inline Date & operator += (Date & lhs, const int number)
{
   lhs.setDate(lhs.getYear(),
               lhs.getMonth(),
               lhs.getDay() + number);

   return lhs;
}

inline Date & operator -= (Date & lhs, const Date & rhs)
{
   lhs.setDate(lhs.getYear() - rhs.getYear(),
               lhs.getMonth() - rhs.getMonth(),
               lhs.getDay() - rhs.getDay());

   return lhs;
}

inline Date & operator -= (Date & lhs, const int number)
{
   lhs.setDate(lhs.getYear(),
               lhs.getMonth(),
               lhs.getDay() - number);

   return lhs;
}

inline Date & operator *= (Date & lhs, const Date & rhs)
{
   lhs.setDate(lhs.getYear() * rhs.getYear(),
               lhs.getMonth() * rhs.getMonth(),
               lhs.getDay() * rhs.getDay());

   return lhs;
}

inline Date & operator *= (Date & lhs, const int number)
{
   lhs.setDate(lhs.getYear(),
               lhs.getMonth(),
               lhs.getDay() + number);

   return lhs;
}

inline Date & operator /= (Date & lhs, const Date & rhs)
{
   lhs.setDate(lhs.getYear() / rhs.getYear(),
               lhs.getMonth() / rhs.getMonth(),
               lhs.getDay() / lhs.getDay());

   return lhs;
}

inline Date & operator /= (Date & lhs, const int number)
{
   lhs.setDate(lhs.getYear(),
               lhs.getMonth(),
               lhs.getDay() / number);

   return lhs;
}

// Increment and Decrement Operators
inline Date & operator ++ (Date & lhs)
{
   return lhs += 1;
}

inline Date & operator -- (Date & lhs)
{
   return lhs -= 1;
}

inline Date operator ++ (Date & rhs, int postfix)
{
   Date old(rhs);
   rhs += 1;
   return old;
}

inline Date operator -- (Date & rhs, int postfix)
{
   Date old(rhs);
   rhs -= 1;
   return old;
}

// Negative and Not Operators
inline Date operator - (const Date & rhs)
{
   return rhs * -1;
}

inline bool operator ! (const Date & rhs)
{
   return (rhs.getYear() == 0 &&
           rhs.getMonth() == 0 &&
           rhs.getDay() == 0);
}

// Comparison Operators
inline bool operator == (const Date & lhs, const Date & rhs)
{
   return (lhs.getYear() == rhs.getYear(),
           lhs.getMonth() == rhs.getMonth(),
           lhs.getDay() == rhs.getDay());
}

inline bool operator != (const Date & lhs, const Date & rhs)
{
   return !(lhs == rhs);
}

inline bool operator > (const Date & lhs, const Date & rhs)
{
   if (lhs.getYear() < rhs.getYear())
      return false;
   else if (lhs.getYear() == rhs.getYear() && lhs.getMonth() < rhs.getMonth())
      return false;
   else if (lhs.getYear() == rhs.getYear() && lhs.getMonth() == rhs.getMonth() &&
       lhs.getDay() < rhs.getDay())
      return false;
   else
      return true;
}

inline bool operator >= (const Date & lhs, const Date & rhs)
{
   return ((lhs > rhs) || (lhs == rhs));
}

inline bool operator < (const Date & lhs, const Date & rhs)
{
   if (lhs.getYear() > rhs.getYear())
      return false;
   else if (lhs.getYear() == rhs.getYear() && lhs.getMonth() > rhs.getMonth())
      return false;
   else if (lhs.getYear() == rhs.getYear() && lhs.getMonth() == rhs.getMonth() &&
       lhs.getDay() > rhs.getDay())
      return false;
   else
      return true;
}

inline bool operator <= (const Date & lhs, const Date & rhs)
{
   return ((lhs < rhs) || (lhs == rhs));
}


#endif // DATE_H
