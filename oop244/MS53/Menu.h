/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-03-13
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#pragma once

#ifndef _SENECA_MENU_H_
#define _SENECA_MENU_H_

#include <iostream>
using namespace std;
namespace seneca
{
    class Menu
    {
        char* m_text;
        int m_noOfSel; 

        bool isValid(int menuChoice) const;

    public:
        Menu(const char* text);
        Menu(const char* text, int NoOfSelections);
        ~Menu(); 

        Menu(const Menu& other);
        Menu& operator=(const Menu& other);

        Menu(Menu&& other) noexcept;
        Menu& operator=(Menu&& other) noexcept;

        ostream& display(ostream& ostr = cout) const;
        int& operator>>(int& selection);
        void menuOptions(const char* text);
        int userMenuChoice() const;
        void setNoOfSelections(int numOfSel);
    };
} 

#endif // SENECA_MENU_H_