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

#ifndef BOOK_H
#define BOOK_H

#include <ostream>
#include "LibraryItem.h"
using namespace std;

namespace seneca {

    class Book : public LibraryItem {
    private:
        char* m_author;
    public:
        Book(const char* title, int year, const char* author);
        Book(const Book& other);
        Book& operator=(const Book& other);
        ~Book();
        ostream& display(ostream& ostr = cout) const override;
        bool operator >(const Book& other) const;
    };
}
#endif //Book_h