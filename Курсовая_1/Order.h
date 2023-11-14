#ifndef COURSE_ORDER_H
#define COURSE_ORDER_H

#include <string>
#include <iostream>

namespace Denis {

struct Date{
    int _day;
    int _month;
    int _year;

    Date(){

        _day = 0;
        _month = 0;
        _year = 0;
    }

    Date(int day, int month, int year){

        _day = day;
        _month = month;
        _year = year;
    };

    ~Date() = default;
    
    bool operator>(const Date& other) const{

        return ((_year > other._year)||
                ((_year == other._year)&&(_month > other._month))||
                ((_year == other._year)&&(_month == other._month)&&(_day > other._day))
        );
    };

    bool operator==(const Date& other) const{

        return ((_year == other._year)&&(_month == other._month)&&(_day == other._day));
    };

    bool operator<(const Date& other) const{

        return (other > *this);
    };

    bool operator>=(const Date& other) const{

        return !(*this < other);
    };

    bool operator<=(const Date& other) const{

        return !(*this > other);
    };

    bool operator!=(const Date& other) const{

        return !(*this == other);
    };

    std::string Print(){

        std::string s = "";
        s += std::to_string(_day) + " " + std::to_string(_month) + " " + std::to_string(_year);
        return s;
    }

};

class Order{
public:
    int _phonnumber;
    std::string _carnumber;
    Date* _date;
    int _time;

    Order(){

        _phonnumber = 0;
        _carnumber = "";
        _date = new Date();
        _time = 0;
    }

    Order(
            int phonenumber,
            std::string carnumber,
            int day,
            int month,
            int year,
            int time) {

        _phonnumber = phonenumber;
        _carnumber = std::move(carnumber);
        _date = new Date(day, month, year);
        _time = time;
    };
    ~Order() = default;
};

}

#endif //COURSE_ORDER_H
