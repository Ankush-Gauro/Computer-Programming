/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-02-04
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#ifndef SENECA_CAR_H
#define SENECA_CAR_H
#define _CRT_SECURE_NO_WARNINGS
namespace seneca {
    class Car {
    private:
        char m_licencePlate[9];
        char* m_makeModel;
        char* m_serviceDesc;
        double m_cost;

    public:
        Car();
        ~Car();
        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
        void display() const;
    };
}

#endif
