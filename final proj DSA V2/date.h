/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (class definition): Defined the class date, which is responsible for storing and manipulating dates.
//* Tested: yes, passed 
//* Notes:
    - This class has support for days, months and years (including leap years). It does not support timestamps (hours, minutes, seconds).
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

//PREPROCESSOR DIRECTIVES
#ifndef DATE_H
#define DATE_H

//HEADER FILES
#include <iostream>
#include <string>

//CLASS date DEFINITION
class date {
public:
    //parametized constructor
    date(int month, int day, int year);
    date();

    bool isLeapYear();

    //operator overloads
    bool operator!=(const date& otherDate) const;
    bool operator<(const date& otherDate) const;
    bool operator<=(const date& otherDate) const;
    bool operator==(const date& otherDate) const;
    bool operator>(const date& otherDate) const;
    bool operator>=(const date& otherDate) const;
    date& operator++();
    date operator++(int);
    date& operator--();
    date operator--(int);
    date& operator+(int daysToAdd);
    date& operator-(int daysToSub);
    friend date& operator+(int daysToAdd, date& addToDate);
    friend date& operator-(int daysToSub, date& subFromDate);
    friend std::istream& operator>>(std::istream& in, date& dateToFill);
    friend std::ostream& operator<<(std::ostream& out, date& dateToPrint);

    //getters and setters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);


private:
    //data fields for representing a date
    int day;
    int month;
    int year;
};

#endif