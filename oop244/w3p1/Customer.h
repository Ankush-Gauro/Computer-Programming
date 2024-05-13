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

#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H
#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"

namespace seneca
{
    class Customer
    {
        int m_id;
        char* m_name;
        const Car* m_car;

    public:
        Customer();
        ~Customer();
        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(int customerId, const char* name, const Car* car);
        void display() const;
        const Car& car() const;
        int getID() const;
        const char* getName() const;
    };
}

#endif
