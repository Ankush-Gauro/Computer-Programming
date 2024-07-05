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

#ifndef TESTPATIENT_H
#define TESTPATIENT_H

#include "Patient.h" 
#include <iostream>
using namespace std;
namespace seneca {
    class TestPatient : public Patient {
    private:
        static int next_Ticket;

    public:
        TestPatient();
        virtual ~TestPatient();
        virtual char type() const override;
        virtual ostream& write(ostream& os) const override;
        virtual istream& read(istream& is) override;
    };

}

#endif // TESTPATIENT_H
