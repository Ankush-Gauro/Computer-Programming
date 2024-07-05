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

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

namespace seneca
{
    bool Menu::isValid(int menuChoice) const
    {
        return menuChoice >= 0 && menuChoice <= m_noOfSel;
    }

    Menu::Menu(const char* text)
    {
        this->menuOptions(text);
        this->setNoOfSelections(2);
    }

    Menu::Menu(const char* text, int NoOfSelections) 
    {
        m_text = new char[strlen(text) + 1];
        strcpy(m_text, text);

        m_noOfSel = NoOfSelections;
    }

    void Menu::menuOptions(const char* text)
    {
        m_text = new char[strlen(text) + 1];
        strcpy(m_text, text);
    }

    void Menu::setNoOfSelections(int numOfSel)
    {
        m_noOfSel = numOfSel;
    }

    Menu::~Menu()
    {
        delete[] m_text;
    }

    ostream& Menu::display(ostream& ostr) const
    {
        if (m_noOfSel == 1)
        {
            istringstream originalText(m_text); 
            char line[256];                          
            while (originalText.getline(line, sizeof(line)))
            {
                ostr << "   " << line << "\n";
            }

            ostr << "   0- Exit\n";
            ostr << "   > ";
        }
        else
        {
            ostr << m_text << '\n';
            ostr << "0- Exit\n";
            ostr << "> ";
        }

        return ostr;
    }

    int Menu::userMenuChoice() const
    {
        bool validEntry = true;
        int selection = 1000;
        do
        {

            cin >> selection;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Bad integer value, try again: ";
                validEntry = false;
            }
            else if (std::cin.peek() == ' ')
            {
                cin.clear();
                cin.ignore(5000, '\n');
                cout << "Only enter an integer, try again: ";
                validEntry = false;
            }
            else
            {
                if (!isValid(selection))
                {
                    cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfSel << "]: ";
                    validEntry = false;
                }
                else
                {
                    validEntry = true;
                }
            }
        } while (!validEntry);
        return selection;
    }

    int& Menu::operator>>(int& Selection)
    {
        display();
        Selection = userMenuChoice();
        return Selection;
    }
}