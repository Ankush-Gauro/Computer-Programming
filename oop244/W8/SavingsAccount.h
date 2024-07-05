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
 // File: SavingAccount.h
 // Version 1.0
 // Date:
 // Author:
 // Description
 // This file defines the SavingsAccount class
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 ***********************************************************************/

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

namespace seneca {
    class SavingsAccount : public Account {
    private:
        double m_interestRate;
    public:
        SavingsAccount(double balance, double interestRate);
        virtual void monthEnd() override;
        virtual void display(std::ostream& os) const override;
    };
}

#endif 