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

#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <iostream>
using namespace std;

namespace seneca {
    class LibraryItem {
    protected:
        char* m_title;
        int m_year;
    public:
        LibraryItem();
        LibraryItem(const char* title, int year);
        LibraryItem(const LibraryItem& other);
        LibraryItem& operator=(const LibraryItem& other);
        virtual ~LibraryItem();
        virtual ostream& display(ostream& ostr = cout) const;
    };
}

#endif //LibraryItem_h