/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-02-17
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

 /***********************************************************************
 // OOP244 Workshop #5 Lab (part 1)
 //
 // File  bankaccount.cpp
 // Version v0.8 Oct 21st 2023
 // Author  Jitesh Arora
 // Description
 //
 // Revision History
 // -----------------------------------------------------------
 // Name                 Date            Reason
 ***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string.h>
#include <iomanip>
#include <cmath>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char* name, bool checking)
	{
		m_userName[0] = '\0';		// Empty string implies is account is not open 
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char* name, bool checking)
	{
		if (isOpen())
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods

	bankAccount::operator bool() const {
		return isOpen();
	}

	bankAccount::operator double() const{

		if (isOpen()){
			return m_funds;
		}
		else{
			return 0.0;
		}
	}

	bankAccount& bankAccount::operator++() {

		double rate;
		if (m_checking) {
			rate = 0.005;
		}
		else {
			rate = 0.025;
		}

		double interest = m_funds * rate;

		if (isOpen() && m_funds > 0) {
			m_funds += interest;
		}

		return *this;
	}

	bankAccount& bankAccount::operator--()
	{
		double transactionCharge;
		if (m_checking) {
			transactionCharge = 1.25;
		}
		else {
			transactionCharge = 3.50;
		}
		
		double fee = m_monthlyTransactions * transactionCharge;

		if (isOpen())
		{
			m_funds -= fee;
		}

		return *this;
	}

	bool bankAccount::operator+= (double amount) {
		if (!isOpen()) {
			return false;
		}

		if (amount < 0) {
			return false;
		}

		m_funds += amount;
		++m_monthlyTransactions;
		cout << "Deposit $" << fixed << setprecision(2) << amount << " for " << m_userName << endl;

		return true;
	}

	bool bankAccount::operator-=(double amount) {
		if (!isOpen()) {
			return false;
		}

		if (amount < 0) {
			return false;
		}

		m_funds -= amount;
		++m_monthlyTransactions;
		amount *= -1;
		cout << "Withdraw $" << fixed << setprecision(2) << amount * -1 << " for " << m_userName << endl;

		return true;
	}


	bool bankAccount::operator== (const bankAccount& other) const {
		bool sameUserName = (strcmp(m_userName, other.m_userName) == 0);


		bool sameFunds = ((m_funds - other.m_funds) < 0.001);


		bool sameType = (m_checking == other.m_checking);


		return (sameUserName && sameFunds && sameType);

	}

	bool bankAccount::operator> (double op) const{

		if (!isOpen()){
			return false;
		}
		return (m_funds > op);

	}

	bool bankAccount::operator<= (double op) const {
		return !(operator>(op));
	}

	bool bankAccount::operator<<(bankAccount& sourceAccount){

		if (isOpen() && sourceAccount.isOpen() && static_cast<double>(sourceAccount) > 0.0){

			cout << "Transfer $" << static_cast<double>(sourceAccount) << " from " << sourceAccount.m_userName << " to " << m_userName << endl;

			double transferFunds = static_cast<double>(sourceAccount);
			if (*this += transferFunds){
				sourceAccount -= transferFunds;
				return true;
			}
			else{
				return false;
			}
			++m_monthlyTransactions;
		}
		else{
			return false;
		}
	}

	void bankAccount::display(void) const {
		if (isOpen()) {
			cout << "Display Account -> User:";

			int mass = 0;
			mass = 16 - strlen(m_userName);

			for (int j = 0; j < mass; j++) {
				cout << "-";
			}

			cout << m_userName << " | ";
			cout << (m_checking ? "Checking" : " Savings") << " | Balance: $";

			int spaces = 0;
			if (m_funds < 0 && m_funds > -100) {
				spaces = 2;
			}
			else if (m_funds > 99) {
				spaces = 2;
			}
			else if (m_funds > -1 && m_funds < 10) {
				spaces = 4;
			}
			else if (m_funds > 9 && m_funds < 100) {
				spaces = 3;
			}

			for (int i = 0; i < spaces; ++i) {
				std::cout << " ";
			}


			cout.precision(2);
			cout << fixed << m_funds;
			cout << " | Transactions:";
			cout.width(3);
			cout.fill('0');
			cout << m_monthlyTransactions << std::endl;

		}
		else {
			cout << "Display Account -> User:------- NOT OPEN" << endl;
		}

	}


	bool operator> (double lhs, const bankAccount& rhs)
	{
		if (!rhs)
			return false;

		return lhs > static_cast<double>(rhs);
	}

	bool operator<= (double lhs, const bankAccount& rhs)
	{
		return !(lhs > rhs);
	}




	// ADD: Global Helper Functions

}