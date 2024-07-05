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

#define _CRT_SECURE_NO_WARNINGS

#include "Patient.h"
#include "Utils.h"
#include <cstring>
#include <iomanip>
#include <limits>
using namespace std;

namespace seneca {
    Patient::Patient(int ticketNumber) : m_ticket(ticketNumber), m_OHIP(0) {
        m_name = nullptr;
    }

    Patient::Patient(const Patient& other) : m_ticket(other.m_ticket) {
        if (other.m_name != nullptr) {
            m_name = new char[std::strlen(other.m_name) + 1];
            std::strcpy(m_name, other.m_name);
        }
        else {
            m_name = nullptr;
        }
        m_OHIP = other.m_OHIP;
    }

    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) {
            delete[] m_name;
            if (other.m_name != nullptr) {
                m_name = new char[std::strlen(other.m_name) + 1];
                std::strcpy(m_name, other.m_name);
            }
            else {
                m_name = nullptr;
            }
            m_OHIP = other.m_OHIP;
            m_ticket = other.m_ticket;
        }
        return *this;
    }

    Patient::~Patient() {
        delete[] m_name;
    }

    bool Patient::operator==(char ch) const {
        return type() == ch;
    }

    bool Patient::operator==(const Patient& other) const {
        return type() == other.type();
    }

    void Patient::setArrivalTime() {
        m_ticket.resetTime();
    }

    Time Patient::time() const {
        return m_ticket.time();
    }

    int Patient::number() const {
        return m_ticket.number();
    }

    Patient::operator bool() const {
        return m_name != nullptr && m_OHIP >= 100000000 && m_OHIP <= 999999999;
    }

    Patient::operator const char* () const {
        return m_name;
    }

    ostream& Patient::write(ostream& ostr) const {
        if (&ostr == &clog) {
            ostr << left << setw(53) << setfill('.') << m_name << right << m_OHIP << "   " << m_ticket;
        }
        else if (&ostr == &cout) {
            if (m_name != nullptr) {
                m_ticket.write(ostr) << endl;
                ostr << m_name << ", OHIP: " << m_OHIP << endl;
            }
            else {
                ostr << "Invalid Patient Record" << endl;
            }
        }
        else {
            ostr << type() << ',' << m_name << ',' << m_OHIP << ',';
            m_ticket.write(ostr);
        }
        return ostr;
    }


    istream& Patient::read(istream& istr) {
        if (&istr == &cin) {
            char tempName[51];
            cout << "Name: ";
            istr.getline(tempName, 51);
            delete[] m_name;
            m_name = new char[strlen(tempName) + 1];
            strcpy(m_name, tempName);
            cout << "OHIP: ";
            while (true) {
                istr >> m_OHIP;
                if (!istr) {
                    cout << "Bad integer value, try again: ";
                    istr.clear();
                    istr.ignore(streamsize(std::numeric_limits<int>::max()), '\n');
                }
                else if (m_OHIP < 100000000 || m_OHIP > 999999999) {
                    cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
                    istr.ignore(std::streamsize(numeric_limits<int>::max()), '\n');
                }
                else {
                    break;
                }
            }
            istr.ignore(std::streamsize(std::numeric_limits<int>::max()), '\n');
        }
        else {
            char tempName[101];
            istr.getline(tempName, 101, ',');
            size_t nameLength = strlen(tempName);
            if (nameLength > 50) {
                tempName[50] = '\0';
            }
            delete[] m_name;
            m_name = new char[strlen(tempName) + 1];
            strcpy(m_name, tempName);
            istr >> m_OHIP;
            istr.ignore(10000, ',');
            if (!m_ticket.read(istr)) {
                istr.setstate(ios::failbit);
            }
        }
        return istr;
    }
}
