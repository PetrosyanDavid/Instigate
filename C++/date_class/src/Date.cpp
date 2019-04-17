#include "Date.hpp"

Date::Date()
{
    day = 2;
    month = 2;
    year = 1990;
    std::cout << "Default constructor called" << std::endl;
}

Date::Date(int x, int y, int z)
{
    if (x > 0 && x < 32){
        day = x;
    } else {
        std::cout << "Invalid day value" << std::endl;
    }
    if (y > 0 && y < 13){
        month = y;
    } else {
        std::cout << "Invalid month value" << std::endl;
    }
    if (z > 1899 && z < 2999){
        year = z;
    } else {
        std::cout << "Invalid month value" << std::endl;
    }
}

void Date::set_date(int x, int y, int z)
{
    if (x > 0 && x < 32){
        day = x;
    } else {
        std::cout << "Invalid day value" << std::endl;
    }
    if (y > 0 && y < 13){
        month = y;
    } else {
        std::cout << "Invalid month value" << std::endl;
    }
    if (z > 1899 && z < 2999){
        year = z;
    } else {
        std::cout << "Invalid month value" << std::endl;
    }
}

void Date::display_date(int f)
{
    if (1 == f) {
        std::cout << "The date is " << day << "." << month << "." << year << std::endl;
    } else if (2 == f) {
        std::cout << "The date is " << day << " " << std::flush;
        switch (month) {
            case 1:
                std::cout << "Jan " << std::flush;
                break;
            case 2:
                std::cout << "Feb " << std::flush;
                break;
            case 3:
                std::cout << "Mar " << std::flush;
                break;
            case 4:
                std::cout << "Apr " << std::flush;
                break;
            case 5:
                std::cout << "May " << std::flush;
                break;
            case 6:
                std::cout << "Jun " << std::flush;
                break;
            case 7:
                std::cout << "Jul " << std::flush;
                break;
            case 8:
                std::cout << "Aug " << std::flush;
                break;
            case 9:
                std::cout << "Sep " << std::flush;
                break;
            case 10:
                std::cout << "Oct " << std::flush;
                break;
            case 11:
                std::cout << "Nov " << std::flush;
                break;
            case 12:
                std::cout << "Dec " << std::flush;
                break;
        }
        std::cout << year << std::endl;
    } else {
        std::cout << "Invalid date format" << std::endl;
    }
}


void Date::compare_date (Date& d)
{
    if (year < d.year || (year == d.year && month < d.month)) {
        std::cout << "We are in the past" << std::endl;
    } else if (year == d.year && month == d.month && day < d.day) {
        std::cout << "We are in the past" << std::endl;
    } else if (year == d.year && month == d.month && day == d.day) {
        std::cout << "Dates are the same" << std::endl;
    } else {
        std::cout << "We are in the future" << std::endl;
    }
}


Date::~Date()
{
    std::cout << "Default deconstructor called" << std::endl;
}
