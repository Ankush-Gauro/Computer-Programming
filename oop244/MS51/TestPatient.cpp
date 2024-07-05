/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-04-09
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#include "TestPatient.h"
#include <iostream>
using namespace std;
namespace seneca {
    int TestPatient::next_Ticket = 1;

    TestPatient::TestPatient() : Patient(next_Ticket++) {}

    TestPatient::~TestPatient() {}

    char TestPatient::type() const {
        return 'C';
    }

    ostream& TestPatient::write(ostream& os) const {
        if (&os == &cout)
            os << "Contagion TEST" << endl;
        return Patient::write(os);
    }

    istream& TestPatient::read(istream& is) {
        Patient::read(is);
        if (&is != &cin)
            next_Ticket = number() + 1;
        return is;
    }
}
