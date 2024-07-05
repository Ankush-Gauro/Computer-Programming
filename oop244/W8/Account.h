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
 // File: Account.h
 // Version 1.0
 // Date:
 // Author:
 // Description
 // This file defines the Account class
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 ***********************************************************************/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "iAccount.h"

namespace seneca {


    class Account : public iAccount {
    private:
        double m_balance;
    protected:
        double balance() const;
    public:
        Account(double balance = 0.0);
        virtual bool credit(double amount) override;
        virtual bool debit(double amount) override;
        virtual void monthEnd() override;
        virtual void display(std::ostream& os) const override;
        virtual ~Account() {};

    };

}
#endif // ACCOUNT_H