/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-03-28
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#include <iostream>
#include "IOAble.h"
using namespace std;

namespace seneca {

    ostream& IOAble::write(ostream& ostr) const {
        return ostr;
    }

    istream& IOAble::read(istream& istr) {
        return istr;
    }

    ostream& operator<<(ostream& ostr, const IOAble& I) {
        return I.write(ostr);
    }

    istream& operator>>(istream& istr, IOAble& I) {
        return I.read(istr);
    }

}