/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-03-20
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include "DepositUtility.h"
using namespace std;

namespace seneca {

    class BankAccount {
    private:
        Date m_openDate;
        DepositInfo m_depInfo;
        double m_balance;
        char m_name[51];

    protected:
        double getBalance() const;
        void setBalance(double balance);
        void writeCurrency(ostream& out, double amount) const;

    public:
        BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
        Date getOpenDate() const;

        virtual ostream& write(ostream& out) const;
        virtual istream& read(istream& in);

        friend istream& operator>>(istream& in, BankAccount& acct);
        friend ostream& operator<<(ostream& out, const BankAccount& acct);
    };
}

#endif // BANKACCOUNT_H