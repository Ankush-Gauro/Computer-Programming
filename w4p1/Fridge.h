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
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H
#include <cstring>
#include <iostream>
using namespace std;
namespace seneca {

    const int FRIDGE_CAP = 3;
    const int NAME_LEN = 20;
    class Food {
        char m_name[NAME_LEN]{};
        int m_weight{};
    public:
        const char* name()const;
        int weight()const;
        Food();
        Food(const char* nm, int wei);
    };

    class Fridge {
        Food m_foods[FRIDGE_CAP];
        int m_numFoods;
        char* m_model;
    public:
        Fridge();
        Fridge(Food farr[], int nf, const char* mod = "Ice Age");
        ~Fridge();
        bool addFood(const Food& f);
        void changeModel(const char* m);
        bool fullFridge() const;
        bool findFood(const char* f) const;
        std::ostream& display(std::ostream& os = std::cout) const;
    };
}

#endif