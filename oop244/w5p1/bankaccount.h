/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-02-17
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_



namespace seneca
{
    const int	 ACCT_MAXLEN_USER = 16;					// Max Length of user name

    // Class Definition
    class bankAccount
    {

    private:
        // Data Members
        char	m_userName[ACCT_MAXLEN_USER];
        double	m_funds;
        bool	m_checking;
        int		m_monthlyTransactions;

        bool isOpen() const;
    public:
        bankAccount(const char* name = nullptr, bool checking = false);
        bool setup(const char* name, bool checking);

        // ADD: Type Conversion, Unary, Binary Operators & Additional Methods
        // ...

        operator bool() const;

        operator double() const;

        bankAccount& operator++();

        bankAccount& operator--();

        bool operator+= (double);

        bool operator-= (double);

        bool operator== (const bankAccount&) const;

        bool operator> (double) const;

        bool operator<= (double) const;

        bool operator<<(bankAccount&);

        void display(void) const;

    };

    // ADD: Global helpers
    // ...

    bool operator> (double lhs, const bankAccount& rhs);

    bool operator<= (double lhs, const bankAccount& rhs);
}
#endif