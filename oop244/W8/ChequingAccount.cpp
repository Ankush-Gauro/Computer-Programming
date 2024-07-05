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
 // File: ChequingAccount.cpp
 // Version 1.0
 // Date:
 // Author:
 // Description
 // This file implements the ChequingAccount class
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 ***********************************************************************/
#include <ostream>
#include <iomanip>
#include "ChequingAccount.h"

namespace seneca {
    ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee)
        : Account(balance), m_transactionFee(transactionFee > 0 ? transactionFee : 0.0), m_monthlyFee(monthlyFee > 0 ? monthlyFee : 0.0) {}

    bool ChequingAccount::credit(double amount) {
        bool success = Account::credit(amount);
        if (success)
            return Account::debit(m_transactionFee);
        return false;
    }

    bool ChequingAccount::debit(double amount) {
        bool success = Account::debit(amount);
        if (success)
            return Account::debit(m_transactionFee);
        return false;
    }

    void ChequingAccount::monthEnd() {
        Account::debit(m_monthlyFee);
    }

    void ChequingAccount::display(std::ostream& os) const {
        os << "Account type: Chequing" << std::endl;
        Account::display(os);
        os << "Per Transaction Fee: " << m_transactionFee << std::endl;
        os << "Monthly Fee: " << std::fixed << std::setprecision(2) << std::showpoint << m_monthlyFee << std::endl;
    }

}