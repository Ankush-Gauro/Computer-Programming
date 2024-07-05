/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-03-26
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

 /***********************************************************************
 // Workshop # 8, Virtual Functions and Abstract Base Classes
 //
 // File: Account.cpp
 // Version 1.0
 // Date:
 // Author:
 // Description
 // This file implements the Account class
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 ***********************************************************************/
#include <ostream>
#include <iomanip>
#include "Account.h"
using namespace std;

namespace seneca {

    Account::Account(double balance) : m_balance(balance > 0 ? balance : 0.0) {}

    double Account::balance() const {
        return m_balance;
    }

    bool Account::credit(double amount) {
        if (amount > 0) {
            m_balance += amount;
            return true;
        }
        return false;
    }

    bool Account::debit(double amount) {
        if (amount > 0 && m_balance >= amount) {
            m_balance -= amount;
            return true;
        }
        return false;
    }

    void Account::monthEnd() {
        
    }

    void Account::display(std::ostream& os) const {
        os << "Balance: $" << fixed << setprecision(2) << m_balance << endl;
    }


}
