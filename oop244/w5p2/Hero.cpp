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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"


namespace seneca {


	void Hero::setEmpty() {
		m_heroName[0] = '\0';
		m_numPowers = 0;
		m_powerLevel = 0;
		m_powerList = nullptr;
	}


	Hero::Hero() {
		setEmpty();
	}


	Hero::Hero(const char* name, Power* power, int numPower) {
		int i, raritySum = 0;
		setEmpty();
		strcpy(m_heroName, name);
		m_numPowers = numPower;
		m_powerList = new Power[numPower];
		for (i = 0; i < m_numPowers; i++) {
			m_powerList[i] = power[i];
		}
		for (i = 0; i < m_numPowers; i++) {
			raritySum += m_powerList[i].checkRarity();
		}
		m_powerLevel = raritySum * m_numPowers;
	}
	
	std::ostream& Hero::display(std::ostream& ostr) const {
		int i;
		ostr << "Name: " << m_heroName << "\n";
		ostr << "List of available powers: ";
		ostr << "\n";
		for (i = 0; i < m_numPowers; i++) {
			ostr << "  Name: " << m_powerList[i].checkName() << ", Rarity: " << m_powerList[i].checkRarity() << "\n";
		}
		ostr << "Power Level: " << m_powerLevel;
		return ostr;
	}


	Hero& Hero::operator+=(Power& power) {
		int i, raritySum = 0;
		Power* temp;
		temp = new Power[m_numPowers];
		for (i = 0; i < m_numPowers; i++) {
			temp[i] = m_powerList[i];
		}
		deallocate();
		m_numPowers++;
		m_powerList = new Power[m_numPowers];
		for (i = 0; i < m_numPowers - 1; i++) {
			m_powerList[i] = temp[i];
		}
		m_powerList[m_numPowers - 1] = power;
		for (i = 0; i < m_numPowers; i++) {
			raritySum += m_powerList[i].checkRarity();
		}
		m_powerLevel = raritySum * m_numPowers;
		delete[] temp;
		return *this;
	}


	Hero& Hero::operator-=(int num) {
		m_powerLevel -= num;
		return *this;
	}
	int Hero::getPowerLevel() const {
		return m_powerLevel;
	}
	bool operator<(Hero& hero1, Hero& hero2) {
		bool isLessThan = false;
		if (hero1.getPowerLevel() < hero2.getPowerLevel())
			isLessThan = true;
		return isLessThan;
	}
	bool operator>(Hero& hero1, Hero& hero2) {
		bool isGreaterThan = false;
		if (hero1.getPowerLevel() > hero2.getPowerLevel())
			isGreaterThan = true;
		return isGreaterThan;
	}
	void operator>>(Power& power, Hero& hero) {
		hero += power;
	}
	void operator<<(Hero& hero, Power& power) {
		hero += power;
	}
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		return hero.display(os);
	}

	void Hero::deallocate() {
		delete[] m_powerList;
	}
	Hero::~Hero() {
		deallocate();
	}

}