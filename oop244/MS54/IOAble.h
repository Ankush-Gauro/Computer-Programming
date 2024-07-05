/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-04-10
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#ifndef IOABLE_H
#define IOABLE_H
#include <iostream>

using namespace std;

namespace seneca {

    class IOAble {

    public:
        virtual ostream& write(ostream& os) const = 0;
        virtual istream& read(istream& is) = 0;

        virtual ostream& csvWrite(ostream& ostr) const {
            return ostr;
        }

        virtual istream& csvRead(istream& istr) {
            return istr;
        }

        virtual ~IOAble() = default;
    };

    ostream& operator<<(ostream& os, const IOAble& obj);
    istream& operator>>(istream& is, IOAble& obj);

}
#endif