/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-03-13
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>


namespace seneca
{
    using namespace std;

    Time& Time::reset()
    {
        m_min = U.getTime();
        return *this;
    }

    Time::Time(unsigned int min)
    {
        m_min = min;
    }

    int Time::toHours(int time) const
    {
        int hours = time / 60;
        return hours;
    }

    int Time::toMinutes(int time) const
    {
        int minutes = time % 60;
        return minutes;
    }

    int Time::hourToInteger(int time) const
    {
        int intHour = time * 60;
        return intHour;
    }

    ostream& Time::write(ostream& ostr) const
    {
        int hours = toHours(m_min);
        int minutes = toMinutes(m_min);
        ostr << setw(2) << setfill('0') << hours << ":";
        ostr << setw(2) << setfill('0') << minutes;
        return ostr;
    }



    std::istream& Time::read(std::istream& istr)
    {

        std::string inp_time;
        int hours, minutes;
        istr >> inp_time;


        bool validInput = true;
        for (char c : inp_time)
        {
            if (!isdigit(c) && c != ':')
            {
                validInput = false;
                break;
            }
        }

        if (!validInput)
        {
            istr.setstate(std::ios::failbit);
            return istr;
        }


        size_t pos = inp_time.find(':');
        if (pos == std::string::npos)
        {
            istr.setstate(std::ios::failbit);
            return istr;
        }

        hours = atoi(inp_time.substr(0, pos).c_str());
        if (hours < 0)
        {
            istr.setstate(std::ios::failbit);
            return istr;
        }

        minutes = atoi(inp_time.substr(pos + 1).c_str());
        if (minutes < 0)
        {
            istr.setstate(std::ios::failbit);
            return istr;
        }

        m_min = hours * 60 + minutes;
        return istr;
    }


    Time::operator int() const
    {
        return m_min;
    }

    Time& Time::operator*=(int val)
    {
        this->m_min = m_min * val;
        return *this;
    }

    Time& Time::operator-=(const Time& D)
    {
        int timeDiff = m_min - D.m_min;
        m_min = (timeDiff >= 0) ? timeDiff : (timeDiff + 1440); 
        return *this;
    }


    ostream& operator<<(ostream& ostr, const Time& T)
    {
        return T.write(ostr);
    }

    istream& operator>>(istream& istr, Time& T)
    {

        return T.read(istr);
    }

    Time Time::operator-(const Time& D) const
    {
        int timeDiff = m_min - D.m_min;
        int result = (timeDiff >= 0) ? timeDiff : (timeDiff + 1440);

        return Time(result);
    }


}
