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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Customer.h"

using namespace std;

namespace seneca
{
    Customer::Customer()
    {
        setEmpty();
    }

    Customer::~Customer()
    {
        deallocateMemory();
    }

    bool Customer::isEmpty() const
    {
        return (m_name == nullptr || m_name[0] == '\0' || m_car == nullptr);
    }

    void Customer::setEmpty()
    {
        m_id = 0;
        m_name = nullptr;
        m_car = nullptr;
    }

    void Customer::deallocateMemory()
    {
        delete[] m_name;
        setEmpty();
    }

    void Customer::set(int customerId, const char* name, const Car* car)
    {
        deallocateMemory();
        if (customerId > 0 && name != nullptr && name[0] != '\0' && car != nullptr)
        {
            m_id = customerId;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_car = car;
        }
        else
        {
            setEmpty();
        }
    }

    void Customer::display() const
    {
        cout << left << setw(15) << "Customer ID: " << right << setw(20) << m_id << endl;
        cout << left << setw(15) << "First Name: " << right << setw(20) << (m_name == nullptr ? "" : m_name) << endl;
        if (m_car != nullptr)
        {
            m_car->display();
        }
    }

    const Car& Customer::car() const
    {
        return *m_car;
    }

    int Customer::getID() const
    {
        return m_id;
    }

    const char* Customer::getName() const
    {
        return m_name;
    }
}
