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
 // File: ChequingAccount.h
 // Version 1.0
 // Date:
 // Author:
 // Description
 // This file defines the Account class
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 ***********************************************************************/

#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H
using namespace std;

#include "Account.h"
namespace seneca {
    class ChequingAccount : public Account {
    private:
        double m_transactionFee;
        double m_monthlyFee;

    public:
        ChequingAccount(double balance, double transactionFee, double monthlyFee);
        virtual bool credit(double amount) override;
        virtual bool debit(double amount) override;
        virtual void monthEnd() override;
        virtual void display(ostream& os) const override;
    };

}
#endif // CHEQUINGACCOUNT_H