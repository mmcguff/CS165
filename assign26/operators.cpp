#include "date.h"

ostream& operator << (ostream& out, const Date& rhs)
{
   if (rhs.postfix == 1)
      rhs.displayDays();
   else if(rhs.isShort)
      rhs.displayShort();
   else
      rhs.displayLong();
  return out;
}

istream& operator >> (istream& in, Date& rhs)
{
   int day, month, year;
   in >> day >> month >> year;
   rhs.year = year;
   rhs.month = month;
   rhs.day = day;
   return in;
}

// Arithmetic Operators
Date Date::operator + (const Date& rhs)
{
   return Date(year + rhs.year, month + rhs.month, day + rhs.day);
}

Date Date::operator + (const int number)
{
   return Date(year, month, day + number);
}

Date Date::operator - (const Date& rhs)
{
   return Date(year - rhs.year, month - rhs.month, day - rhs.day, 1);
}

Date Date::operator - (const int number)
{
   return Date(year, month, day - number);
}

Date operator - (const int number, Date & rhs)
{
   return Date(rhs.getYear(), rhs.getMonth(), number - rhs.getDay());
}

Date Date::operator * (const Date& rhs)
{
   return Date(year * rhs.year, month * rhs.month, day * rhs.day);
}

Date Date::operator * (const int number)
{
   return Date(year, month, day * number);
}

Date Date::operator / (const Date& rhs)
{
   return Date(year / rhs.year, month / rhs.month, day / rhs.day);
}

Date Date::operator / (const int number)
{
   return Date(year, month, day / number);
}

// Assignment Operator
Date & Date:: operator = (const Date& rhs)
{
   this->year = rhs.year;
   this->month = rhs.month;
   this->day = rhs.day;
   return *this;
}

// Add-onto Operators
Date& Date::operator += (const Date& rhs)
{
   *this = (*this + rhs);
   return *this;
}

Date& Date::operator += (const int number)
{
   *this = (*this + number);
   return *this;
}

Date& Date::operator -= (const Date& rhs)
{
   *this = (*this - rhs);
   return *this;
}

Date& Date::operator -= (const int number)
{
   *this = (*this - number);
   return *this;
}

Date& Date::operator *= (const Date& rhs)
{
   *this = (*this * rhs);
   return *this;
}

Date& Date::operator *= (const int number)
{
   *this = (*this * number);
   return *this;
}

Date& Date::operator /= (const Date& rhs)
{
   *this = (*this / rhs);
   return *this;
}

Date& Date::operator /= (const int number)
{
   *this = (*this / number);
   return *this;
}

// Increment and Decrement Operators
Date& Date::operator ++ ()
{
   return (*this += 1);
}

Date& Date::operator -- ()
{
   return (*this -= 1);
}

Date Date::operator ++ (int postfix)
{
   Date old(*this);
   *this += 1;
   return old;
}

Date Date::operator-- (int postfix)
{
   Date old(*this);
   *this -= 1;
   return old;
}

// Negative and Not Operators
Date Date::operator - ()
{
   return (*this * -1);
}

bool Date::operator ! ()
{
   return (this->year == 0 && this->month == 0 && this->day == 0);
}

// Comparison Operators
bool Date::operator == (const Date & rhs)
{
   
   return (this->year == rhs.year && this->month == rhs.month 
            && this->day == rhs.day);
}

bool Date::operator != (const Date & rhs)
{
   return !(*this == rhs);
}

bool Date::operator > (const Date & rhs)
{
   if (this->year <= rhs.year)
      return false;
   else if (this->year == rhs.year && this->month <= rhs.month)
      return false;
   else if (this->year == rhs.year && this->month == rhs.month && this->day <= rhs.day)
      return false;
   else 
      return true;
}

bool Date::operator >= (const Date & rhs)
{
   return ((*this > rhs) || (*this == rhs));
}

bool Date::operator < (const Date & rhs)
{
   if (this->year >= rhs.year)
      return false;
   else if (this->year == rhs.year && this->month >= rhs.month)
      return false;
   else if (this->year == rhs.year && this->month == rhs.month && this->day >= rhs.day)
      return false;
   else 
      return true;
}

bool Date::operator <= (const Date & rhs)
{
   return ((*this < rhs) || (*this == rhs));
}
