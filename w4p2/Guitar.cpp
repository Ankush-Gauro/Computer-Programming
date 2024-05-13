/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-02-14
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

 /***********************************************************************
 // OOP244 Workshop #4 p2: tester program
 //
 // Version 1.0
 // Date: Summer 2023
 // Author Michael Huang
 // Description
 //
 // Revision History
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 //
 /////////////////////////////////////////////////////////////////
 ***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca {

    GuitarStr::GuitarStr() {};

    GuitarStr::GuitarStr(const char* ma, double ga) {
        strncpy(m_material, ma, MAT_LEN);
        m_gauge = ga;
    };

    const char* GuitarStr::material() const {
        return m_material;
    }

    double GuitarStr::gauge() const {
        return m_gauge;
    }

    Guitar::Guitar(const char* mod) {
        m_strings = nullptr;
        m_numStrings = 0;
        m_model = new char[strlen(mod) + 1];
        strcpy(m_model, mod);
    }


    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) {

        if (ns <= 0 || mod == nullptr || strs == nullptr) {

            return;
        }

        m_model = new char[strlen(mod) + 1];
        strcpy(m_model, mod);

        m_strings = new GuitarStr[ns];

        for (int i = 0; i < ns; ++i) {
            m_strings[i] = strs[i];
        }

        m_numStrings = ns;
    }

    Guitar::~Guitar()
    {
        delete[] m_strings;
        delete[] m_model;
    }

    bool Guitar::changeString(const GuitarStr& gs, int sn)
    {
        if (sn >= 0 && sn < m_numStrings) 
        {
            m_strings[sn] = gs;
            return true;
        }
        return false;
    }

    void Guitar::reString(GuitarStr strs[], int ns)
    {
        delete[] m_strings;
        m_strings = new GuitarStr[ns];
        for (int i = 0; i < ns; ++i)
        {
            m_strings[i] = strs[i];
        }
        m_numStrings = ns;
    }

    void Guitar::deString() {
        delete[] m_strings;
        m_strings = nullptr;
        m_numStrings = 0;
    }

    bool Guitar::strung() const {
        return(m_strings != nullptr && m_numStrings > 0);
    }

    bool Guitar::matchGauge(double ga) const {
        for (int i = 0; i < m_numStrings; ++i) {
            if (m_strings[i].gauge() == ga) {
                return true;
            }
        }
        return false;
    }

    ostream& Guitar::display(ostream& os) const {

        if (m_model == nullptr || m_strings == nullptr || m_numStrings <= 0) {
            os << "***Empty Guitar***" << endl;
        }
        else {
            os << "Guitar Model: " << m_model << endl;
            os << "Strings: " << m_numStrings << endl;

            for (int i = 0; i < m_numStrings; ++i) {
                os << "#" << (i + 1);

                os << right << setw(MAT_LEN) << m_strings[i].material() << " | ";

                os << fixed << setprecision(1) << m_strings[i].gauge() << endl;
            }

        }
        return os;


    }

}