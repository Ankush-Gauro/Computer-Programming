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
#include "TriagePatient.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace seneca {
    int TriagePatient::next_Ticket = 1;

    TriagePatient::TriagePatient() : Patient(next_Ticket++), symptoms(nullptr) {}

    TriagePatient::TriagePatient(const TriagePatient& otherpatient) : Patient(otherpatient), symptoms(nullptr) {
        if (otherpatient.symptoms) {
            int length = strlen(otherpatient.symptoms);
            if (length > 512) {
                length = 512;
            }
            symptoms = new char[length + 1];
            strncpy(symptoms, otherpatient.symptoms, length);
            symptoms[length] = '\0';
        }
    }

    TriagePatient& TriagePatient::operator=(const TriagePatient& otherpatient) {
        if (this != &otherpatient) {
            Patient::operator=(otherpatient);
            delete[] symptoms;
            symptoms = nullptr;
            if (otherpatient.symptoms) {
                int length = strlen(otherpatient.symptoms);
                if (length > 512) {
                    length = 512;
                }
                symptoms = new char[length + 1];
                strncpy(symptoms, otherpatient.symptoms, length);
                symptoms[length] = '\0';
            }
        }
        return *this;
    }

    TriagePatient::~TriagePatient() {
        delete[] symptoms;
    }

    char TriagePatient::type() const {
        return 'T';
    }

    ostream& TriagePatient::write(ostream& os) const {
        if (&os == &cout) {
            os << "TRIAGE";
            os << endl;
            Patient::write(os);
            os << "Symptoms: " << symptoms << endl;
        }
        else if (&os != &clog) {
            Patient::write(os);
            os << "," << symptoms;
        }
        else {
            Patient::write(os);
        }
        return os;
    }

    istream& TriagePatient::read(istream& is) {
        delete[] symptoms;
        Patient::read(is);
        if (&is != &cin) {
            char comma;
            is >> comma;
        }
        char t[512];
        if (&is == &cin) {
            cout << "Symptoms: ";
        }
        is.getline(t, 512);
        int i = strlen(t);
        if (i > 0) {
            if (t[i - 1] == '\n') {
                t[i - 1] = '\0';
            }
            i = strlen(t);
            if (i > 512) {
                i = 512;
            }
            symptoms = new char[i + 1];
            strncpy(symptoms, t, i);
            symptoms[i] = '\0';
        }
        if (is.fail() || is.eof()) {
            delete[] symptoms;
            symptoms = nullptr;
        }
        if (&is != &cin) {
            next_Ticket = number() + 1;
        }
        return is;
    }
}
