/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-04-04
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#ifndef TRIAGEPATIENT_H
#define TRIAGEPATIENT_H
#include "Patient.h"
using namespace std;

namespace seneca {
    class TriagePatient : public Patient {
    private:
        static int next_Ticket;
        char* symptoms;

    public:
        TriagePatient();
        TriagePatient(const TriagePatient& other);
        TriagePatient& operator=(const TriagePatient& other);
        virtual ~TriagePatient();

        virtual char type() const override;
        virtual ostream& write(ostream& os) const override;
        virtual istream& read(istream& is) override;
    };
}

#endif // TRIAGEPATIENT_H