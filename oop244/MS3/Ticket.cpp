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
#include "Ticket.h"
using namespace std;

namespace seneca {
    Ticket::Ticket(int number) {
        m_number = number;
    }

    Time Ticket::time() const {
        return m_time;
    }

    int Ticket::number() const {
        return m_number;
    }

    void Ticket::resetTime() {
        m_time.reset();
    }

    ostream& Ticket::csvWrite(ostream& ostr) const {
        ostr << m_number << " " << m_time;
        return ostr;
    }

    istream& Ticket::csvRead(istream& istr) {
        char delimiter;
        istr >> m_number >> delimiter >> m_time;
        return istr;
    }

    ostream& Ticket::write(ostream& ostr) const {
        if (&ostr == &cout) {
            ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
        }
        else if (&ostr == &clog) {
            ostr << m_number << " " << m_time;
        }
        else {
            ostr << m_number << "," << m_time;
        }
        return ostr;
    }

    istream& Ticket::read(istream& istr) {
        istr >> m_number;
        istr.ignore();
        return istr >> m_time;
    }
}