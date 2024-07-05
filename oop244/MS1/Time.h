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

#pragma once
#ifndef SENECA_TIME_H
#define SENECA_TIME_H
#include <iostream>
using namespace std;
namespace seneca {
	class Time {
		unsigned int m_min;
	public:
		Time& reset();
		Time(unsigned int min = 0);
		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);
		operator int()const;
		Time& operator *= (int val);
		Time& operator-=(const Time& D);
		Time operator-(const Time& D) const;
		int toHours(int time) const;
		int toMinutes(int time) const;
		int hourToInteger(int time) const;
		void printAMPM() const;
	};
	istream& operator>>(istream& istr, Time& T);
	ostream& operator<<(ostream& ostr, const Time& T);
}
#endif // !SENECA_TIME_H

