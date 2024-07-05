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
// File: iAccount.h
// Version 1.0
// Date:
// Author:
// Description
// This file defines the iAccount interface
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#ifndef IACCOUNT_H
#define IACCOUNT_H

#include <iostream>
namespace seneca {
    class iAccount {
    public:
        virtual bool credit(double) = 0;
        virtual bool debit(double) = 0;
        virtual void monthEnd() = 0;
        virtual void display(std::ostream&) const = 0;
        virtual ~iAccount() {}
    };

    iAccount* CreateAccount(const char*, double);
}
#endif // IACCOUNT_H