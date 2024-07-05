/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-02-21
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */
#pragma once
#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include <iostream>
#include "Power.h"

namespace seneca {
	class Hero {
		char m_heroName[MAX_NAME_LENGTH];
		Power* m_powerList;
		int m_numPowers;
		int m_powerLevel;
		void setEmpty();
	public:
		Hero();
		Hero(const char* name, Power* power, int numPower);
		std::ostream& display(std::ostream& ostr = std::cout) const;
		Hero& operator+=(Power&);
		Hero& operator-=(int);
		void deallocate();
		~Hero();
		int getPowerLevel() const;
	};
	bool operator<(Hero& hero1, Hero& hero2);
	bool operator>(Hero& hero1, Hero& hero2);
	void operator>>(Power&, Hero&);
	void operator<<(Hero&, Power&);
	std::ostream& operator<<(std::ostream& os, const Hero& hero);
}

#endif