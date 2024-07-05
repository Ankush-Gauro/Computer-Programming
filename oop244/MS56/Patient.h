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

#ifndef PATIENT_H
#define PATIENT_H

#include "Ticket.h"
#include "IOAble.h"
#include "Time.h"
#include <iostream>
using namespace std;
namespace seneca {
    class Patient : public IOAble {
        Ticket m_ticket;
        int m_OHIP;
        char* m_name;
    public:
        Patient(int ticketNumber = 0);
        Patient(const Patient& other);
        Patient& operator=(const Patient& other);

        virtual ~Patient();
        virtual char type() const = 0;
        bool operator==(char ch) const;
        bool operator==(const Patient& other) const;

        operator bool() const;
        operator const char* () const;
        void setArrivalTime();
        Time time() const;
        int number() const;

        ostream& write(ostream& ostr) const override;
        istream& read(istream& istr) override;
    };
}

#endif // PATIENT_H