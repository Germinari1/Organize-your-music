/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class implementation): Implements the class date, which is responsible for storing and manipulating dates.
//* Tested: yes, passed 
//* Notes:
    - This class has support for days, months and years (including leap years). It does not support timestamps (hours, minutes, seconds).
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

//HEADER FILES
#include "date.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <numeric>

int getDaysInMonth(date& dateGetDays);

bool preInstanceIsLeapYear(int yearPreInstance){
  if (yearPreInstance % 4 == 0) {
    if (yearPreInstance % 100 == 0) {
      if (yearPreInstance % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  } else {
    return false;
  }
}

date::date()
{
  month = 1;
  day = 1;
  year = 1970;
}

date::date(int month_p, int day_p, int year_p) {

  bool invalid_date = (year_p < 0)
    || (month_p < 1 || month_p > 12)
    || (month_p == 2 && day_p > 28 && !preInstanceIsLeapYear(year_p))
    || (month_p == 2 && day_p > 29 && preInstanceIsLeapYear(year_p))
    || (month_p == 4 && day_p > 30)
    || (month_p == 6 && day_p > 30)
    || (month_p == 9 && day_p > 30)
    || (month_p == 11 && day_p > 30)
    || (day_p > 31);

  if (invalid_date) {
    std::cout << "Invalid date. Setting to January 1, 2000." << std::endl;
    month_p = 1;
    day_p = 1;
    year_p = 2000;
  }

  month = month_p;
  day = day_p;
  year = year_p;
}

bool date::isLeapYear() {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  } else {
    return false;
  }
}

bool date::operator!=(const date& otherDate) const {
  return !(*this == otherDate);
}

bool date::operator<(const date& otherDate) const {
  if (year < otherDate.year) {
    return true;
  }
  if (year == otherDate.year && month < otherDate.month) {
    return true;
  }
  if (year == otherDate.year && month == otherDate.month && day < otherDate.day) {
    return true;
  }
  return false;
}

bool date::operator<=(const date& otherDate) const {
  return (*this < otherDate) || (*this == otherDate);
}

bool date::operator==(const date& otherDate) const {
  return (year == otherDate.year && month == otherDate.month && day == otherDate.day);
}

bool date::operator>(const date& otherDate) const {
  return !(*this <= otherDate);
}

bool date::operator>=(const date& otherDate) const {
  return !(*this < otherDate);
}

int getDaysInMonth(date& dateGetDays) {

  int month = dateGetDays.getMonth();
  int year = dateGetDays.getYear();

  // Handle February
  if(month == 2) {
    if(dateGetDays.isLeapYear()) {
      return 29; // Leap year Feb
    } else {
      return 28; // Non-leap year Feb
    }
  }

  // 30 days months
  if(month == 4 || month == 6 ||
     month == 9 || month == 11) {
    return 30;
  }

  // All others have 31 days
  return 31;

}


date& date::operator++() {

  // Increment day
  day++;

  // Check if day exceeded max days in current month
  if(day > getDaysInMonth(*this)) {

    // Reset day to 1, increment month
    day = 1;
    month++;

    // Check if month over 12
    if(month > 12) {
      month = 1;
      year++;
    }

  }

  return *this;

}

date date::operator++(int) {
  date copy = *this;
  ++(*this);
  return copy;
}


date& date::operator--() {

  // Decrement day
  day--;

  // Check if day went below 1
  if(day < 1) {

    // Decrement month
    month--;

    // Handle month underflow
    if(month < 1) {
      month = 12;
      year--;
    }

    // Set day to max days in new month
    day = getDaysInMonth(*this);

  }

  return *this;

}

date date::operator--(int) {
  date copy = *this;
  --(*this);
  return copy;
}


date& date::operator+(int daysToAdd) {

  // Add days
  day += daysToAdd;

  // Handle overflow with loop
  while(day > getDaysInMonth(*this)) {

    // Subtract max days of current month
    day -= getDaysInMonth(*this);

    // Increment month
    month++;

    // Handle month overflow
    if(month > 12) {
      month = 1;
      year++;
    }

  }

  return *this;

}


date& date::operator-(int daysToSub) {

  // Subtract days
  day -= daysToSub;

  // Handle underflow with loop
  while(day < 1) {

    // Decrement month
    month--;

    // Handle month underflow
    if(month < 1) {
      month = 12;
      year--;
    }

    // Add max days of new month
    day += getDaysInMonth(*this);

  }

  return *this;

}

int date::getDay() const {
  return day;
}

int date::getMonth() const {
  return month;
}

int date::getYear() const {
  return year;
}

void date::setDay(int day_p) {
  if (day_p < 1 || day_p > 31) {
    std::cout << "Invalid day value. No change made." << std::endl;
  } else {
    day = day_p;
  }
}

void date::setMonth(int month_p) {
  if (month_p < 1 || month_p > 12) {
    std::cout << "Invalid month value. No change made." << std::endl;
  } else {
    month = month_p;
  }
}

void date::setYear(int year_p) {
  if (year_p < 0) {
    std::cout << "Invalid year value. No change made." << std::endl;
  } else {
    year = year_p;
  }
}

date& operator+(int daysToAdd, date& addToDate) {
  return addToDate + daysToAdd;
}

date& operator-(int daysToSub, date& subFromDate) {
  return subFromDate - daysToSub;
}


std::istream& operator>>(std::istream& in, date& dateToFill) {
  int month, day, year;
  in >> month >> day >> year;
  dateToFill.setMonth(month);
  dateToFill.setDay(day);
  dateToFill.setYear(year);
  return in;
}

std::ostream& operator<<(std::ostream& out, date& dateToPrint) {
  out << dateToPrint.getYear() << "-"
      << std::setfill('0') << std::setw(2) << dateToPrint.getMonth() << "-"
      << std::setfill('0') << std::setw(2) << dateToPrint.getDay();
  return out;
}