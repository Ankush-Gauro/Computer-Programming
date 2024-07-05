/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-03-31
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS
#include "LibraryItem.h"
#include <ostream>
#include <iomanip>
#include <cstring>
using namespace std;

namespace seneca {
    LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

    LibraryItem::LibraryItem(const char* title, int year) : m_year(year) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    }

    LibraryItem::LibraryItem(const LibraryItem& other) : m_year(other.m_year) {
        m_title = new char[strlen(other.m_title) + 1];
        strcpy(m_title, other.m_title);
    }

    LibraryItem& LibraryItem::operator=(const LibraryItem& other) {
        if (this != &other) {
            delete[] m_title;
            m_year = other.m_year;
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        }
        return *this;
    }

    LibraryItem::~LibraryItem() {
        delete[] m_title;
    }

    ostream& LibraryItem::display(ostream& ostr) const {
        ostr << "Title: " << m_title << " (" << m_year << ")";
        return ostr;
    }

}