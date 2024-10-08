/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-04-09
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
namespace seneca {
    class Time {
        unsigned int m_min;

    public:
        Time(unsigned int min = 0u);
        Time& reset();
        ostream& write(ostream& os) const;
        istream& read(istream& istr);
        operator unsigned int() const;
        Time& operator*=(int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
    };
    ostream& operator<<(ostream& os, const Time& time);
    istream& operator>>(istream& is, Time& time);
}

#endif // TIME_H