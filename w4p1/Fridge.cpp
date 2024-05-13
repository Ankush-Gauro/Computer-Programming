/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-02-11
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Fridge.h"
using namespace std;

namespace seneca {

    const char* Food::name() const {
        return m_name;
    }
    int Food::weight() const {
        return m_weight;
    }
    Food::Food() {}

    Food::Food(const char* nm, int wei) {
        strncpy(m_name, nm, NAME_LEN);
        m_weight = wei;
    }

    Fridge::Fridge() : m_numFoods(0), m_model(nullptr) {
        m_model = new char[1];
        m_model[0] = '\0';
    }

    Fridge::Fridge(Food farr[], int nf, const char* mod) : m_numFoods(0), m_model(nullptr) {
        if (nf > 0 && mod != nullptr && mod[0] != '\0') {
            m_model = new char[strlen(mod) + 1];
            strcpy(m_model, mod);

            int foodsToAdd = nf < FRIDGE_CAP ? nf : FRIDGE_CAP;
            for (int i = 0; i < foodsToAdd; ++i) {
                m_foods[i] = farr[i];
                ++m_numFoods;
            }
        }
        else {
            m_model = new char[1];
            m_model[0] = '\0';
        }
    }


    Fridge::~Fridge() {
        delete[] m_model;
    }

    bool Fridge::addFood(const Food& f) {
        if (m_numFoods < FRIDGE_CAP) {
            m_foods[m_numFoods++] = f;
            return true;
        }
        return false;
    }

    void Fridge::changeModel(const char* m) {
        if (m != nullptr && m[0] != '\0') {
            delete[] m_model;
            m_model = new char[strlen(m) + 1];
            strcpy(m_model, m);
        }
    }

    bool Fridge::fullFridge() const {
        return m_numFoods >= FRIDGE_CAP;
    }

    bool Fridge::findFood(const char* f) const {
        for (int i = 0; i < m_numFoods; ++i) {
            if (strcmp(m_foods[i].name(), f) == 0) {
                return true;
            }
        }
        return false;
    }

    std::ostream& Fridge::display(std::ostream& os) const {
        if (m_model[0] == '\0') {
            return os;
        }

        os << "Fridge Model: " << m_model << "\n";
        os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << "\n";
        os << "List of Foods\n";
        for (int i = 0; i < m_numFoods; ++i) {
            os << std::setw(NAME_LEN) << m_foods[i].name() << " | " << m_foods[i].weight() << "\n";
        }
        return os;
    }

}