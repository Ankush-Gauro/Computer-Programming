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
#include <iostream>
#include <ostream>
#include <iomanip>
#include <string.h>
#include "Book.h"
using namespace std;

namespace seneca {
    Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year) {
        m_author = new char[strlen(author) + 1];
        strcpy(m_author, author);
    }

    Book::Book(const Book& other) : LibraryItem(other), m_author(nullptr) {
        m_author = new char[strlen(other.m_author) + 1];
        strcpy(m_author, other.m_author);
    }

    Book& Book::operator=(const Book& other) {
        if (this != &other) {
            LibraryItem::operator=(other);
            delete[] m_author;
            m_author = new char[strlen(other.m_author) + 1];
            strcpy(m_author, other.m_author);
        }
        return *this;
    }

    Book::~Book() {
        delete[] m_author;
    }

    ostream& Book::display(ostream& ostr) const {
        LibraryItem::display(ostr);
        ostr << endl << "Author: " << m_author;
        return ostr;
    }

    bool Book::operator >(const Book& other) const {
        if (m_author != nullptr && other.m_author != nullptr) {
            return strcmp(m_author, other.m_author) > 0;
        }
        return false;
    }
}