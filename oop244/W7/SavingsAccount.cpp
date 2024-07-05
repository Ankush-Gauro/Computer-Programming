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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
#include "DepositUtility.h"
#include "BankAccount.h"
using namespace std;
namespace seneca {

    SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate)
        : BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}

    void SavingsAccount::writeInterest(ostream& out) const {
        out << fixed << setprecision(3) << m_interest << "%";
    }

    void SavingsAccount::applyInterest(Date& dt) {
        Date originalInteresdate = m_interestDate;
        double originalBalance = getBalance();
        double interestAmount = originalBalance * m_interest;
        setBalance(originalBalance + interestAmount);
        m_interestDate = dt;
        cout << "   " << '$' << fixed << setprecision(2) << originalBalance << " + $" << interestAmount << " (";
        writeInterest(cout);
        cout << ") = $" << fixed << setprecision(2) << getBalance() << " | " << originalInteresdate << " => " << m_interestDate << endl;
    }

    ostream& SavingsAccount::write(ostream& out) const {
        BankAccount::write(out);
        out << " | ";
        writeInterest(out);
        out << " | " << m_interestDate;
        return out;
    }

    istream& SavingsAccount::read(istream& in) {
        BankAccount::read(in);
        cout << "Interest Date ";
        in >> m_interestDate;
        cout << "Interest Rate: ";
        in >> m_interest;
        return in;
    }

    istream& operator>>(istream& in, SavingsAccount& acct) {
        return acct.read(in);
    }

    ostream& operator<<(ostream& out, const SavingsAccount& acct) {
        return acct.write(out);
    }

}