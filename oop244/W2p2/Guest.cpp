/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-02-01
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Guest.h"
using namespace std;

namespace seneca {

   
    void set(Guest& guest, const char* first, const char* last, int age) {
        int firstLen = 0;
        while (first != nullptr && first[firstLen] != '\0') {
            firstLen++;
        }
        int lastLen = 0;
        while (last != nullptr && last[lastLen] != '\0') {
            lastLen++;
        }
        if (first != nullptr && last != nullptr && firstLen > 0 && lastLen > 0) {
            guest.m_firstname = new char[firstLen + 1];
            for (int i = 0; i < firstLen; ++i) {
                guest.m_firstname[i] = first[i];
            }

            guest.m_firstname[firstLen] = '\0';

            guest.m_lastname = new char[lastLen + 1];

            for (int i = 0; i < lastLen; ++i) {
                guest.m_lastname[i] = last[i];
            }
            guest.m_lastname[lastLen] = '\0';
        }
        else {
            guest.m_firstname = nullptr;
            guest.m_lastname = nullptr;
        }

        guest.m_adult = (age > 17);
    }

    void print(const Guest& guest) {
    if (guest.m_firstname == nullptr || guest.m_lastname == nullptr) {
        cout << "Vacated!" << endl;
    }
    else {
        if (guest.m_adult == true) {
            cout << guest.m_firstname << " " << guest.m_lastname << endl;
        }
        else {
            cout << guest.m_firstname << " " << guest.m_lastname << "(Child)" << endl;
        }
    }
}

    void book(Guest& guest) {
        string firstName, lastName;
        int adult;

        cout << "Name: ";
        cin >> firstName;
        cout << "Lastname: ";
        cin >> lastName;
        cout << "Age: ";
        cin >> adult;

        guest.m_firstname = new char[firstName.length() + 1];
        guest.m_lastname = new char[lastName.length() + 1];

        for (size_t i = 0; i < firstName.length(); ++i) {
            guest.m_firstname[i] = firstName[i];
        }
        guest.m_firstname[firstName.length()] = '\0';

        for (size_t i = 0; i < lastName.length(); ++i) {
            guest.m_lastname[i] = lastName[i];
        }
        guest.m_lastname[lastName.length()] = '\0';

        if (adult >= 18) {
            guest.m_adult = true;
        }
        else {
            guest.m_adult = false;
        }
    }

    
    void vacate(Guest& guest) {
        delete[] guest.m_firstname;
        guest.m_firstname = nullptr;
        delete[] guest.m_lastname;
        guest.m_lastname = nullptr;
        guest.m_adult = false;

    }

}
