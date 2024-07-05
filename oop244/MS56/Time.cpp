/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-04-10
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include "Time.h"
#include "Utils.h"  
using namespace std;

namespace seneca {

    Time::Time(unsigned int min) : m_min(min) {}

    Time& Time::reset() {
        m_min = U.getTime();

        return *this;
    }
    ostream& Time::write(ostream& os) const {
        os << setw(2) << setfill('0') << m_min / 60 << ":"
            << setw(2) << setfill('0') << m_min % 60;
        return os;
    }

    istream& Time::read(istream& istr) {
        int hour = 0, min = 0;
        char colon;
        istr >> hour >> colon >> min;
        if (istr.fail() || colon != ':' || hour < 0 || hour > 23 || min < 0 || min > 59) {
            istr.setstate(ios::failbit);
        }
        else {
            m_min = hour * 60 + min;
        }
        return istr;
    }

    Time::operator unsigned int() const {
        return m_min;
    }

    ostream& operator<<(ostream& os, const Time& time) {
        return time.write(os);
    }

    istream& operator>>(istream& is, Time& time) {
        return  time.read(is);;
    }

    Time& Time::operator*=(int val) {
        m_min *= val;
        return *this;
    }

    Time& Time::operator-=(const Time& D) {
        int diff = m_min - D.m_min;
        if (diff < 0) {
            diff += 1440;
        }
        m_min = diff;
        return *this;
    }

    Time Time::operator-(const Time& T) const {
        int diff = m_min - T.m_min;
        if (diff < 0) {
            diff += 24 * 60;
        }
        return Time(diff);
    }
}