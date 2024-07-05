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
 // File: SavingsAccount.cpp
 // Version 1.0
 // Date:
 // Author:
 // Description
 // This file implements the SavingsAccount class
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 ***********************************************************************/

#include <ostream>
#include <iomanip>
#include "SavingsAccount.h"
using namespace std;

namespace seneca {

    SavingsAccount::SavingsAccount(double balance, double interestRate)
        : Account(balance), m_interestRate(interestRate > 0 ? interestRate : 0.0) {}

    void SavingsAccount::monthEnd() {
        double interestEarned = balance() * m_interestRate;
        credit(interestEarned);
    }

    void SavingsAccount::display(ostream& os) const {
        os << "Account type: Savings\n";
        Account::display(os);
        os << "Interest Rate (%): " << fixed << setprecision(2) << m_interestRate * 100 << endl;
    }
}
