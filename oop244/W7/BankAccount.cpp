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
#include "BankAccount.h"
#include "DepositUtility.h"
using namespace std;

namespace seneca {

    Date BankAccount::getOpenDate() const {
        return m_openDate;
    }

    BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
        : m_openDate(openDate), m_depInfo(depInfo), m_balance(balance) {
        strncpy(m_name, name, 50);
        m_name[50] = '\0';
    }

    double BankAccount::getBalance() const {
        return m_balance;
    }

    void BankAccount::setBalance(double balance) {
        m_balance = balance;
    }

    void BankAccount::writeCurrency(ostream& out, double amount) const {
        out << '$' << fixed << setprecision(2) << amount;
    }

    ostream& BankAccount::write(ostream& out) const {
        out << ">> " << m_name << " | ";
        writeCurrency(out, m_balance);
        out << " | " << m_openDate << " | " << m_depInfo;
        return out;
    }

    istream& BankAccount::read(istream& in) {

        cout << "Name: ";
        in.getline(m_name, 51);
        cout << "Opening Balance: ";
        in >> m_balance;
        in.ignore();
        cout << "Date Opened ";
        in >> m_openDate;
        in.ignore();
        cout << "";
        in >> m_depInfo;
        in.ignore();
        return in;
    }

    istream& operator>>(istream& in, BankAccount& acct) {
        return acct.read(in);
    }

    ostream& operator<<(ostream& out, const BankAccount& acct) {
        return acct.write(out);
    }

}