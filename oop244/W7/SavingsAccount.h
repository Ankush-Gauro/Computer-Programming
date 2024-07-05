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

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
#include "DepositUtility.h"
using namespace std;

namespace seneca {

    class SavingsAccount : public BankAccount {
    private:
        double m_interest;
        Date m_interestDate;
        void writeInterest(ostream& out) const;

    public:
        SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
        void applyInterest(Date& dt);
        ostream& write(ostream& out) const override;
        istream& read(istream& in) override;
        friend istream& operator>>(istream& in, SavingsAccount& acct);
        friend ostream& operator<<(ostream& out, const SavingsAccount& acct);
    };
}
#endif // SAVINGSACCOUNT_H