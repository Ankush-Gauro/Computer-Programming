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
#include "Car.h"

using namespace std;

namespace seneca {
    Car::Car() {
        setEmpty();
    }

    Car::~Car() {
        deallocateMemory();
    }

    bool Car::isEmpty() const {
        return (m_makeModel == nullptr || m_serviceDesc == nullptr || m_licencePlate[0] == '\0');
    }

    void Car::setEmpty()
    {
        m_licencePlate[0] = '\0';
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
        m_cost = 0.0;
    }


    void Car::deallocateMemory()
    {
        delete[] m_makeModel;
        delete[] m_serviceDesc;
        setEmpty();
    }

    void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost)
    {
        deallocateMemory();
        if (plateNo[0] != '\0' && carMakeModel != nullptr && carMakeModel[0] != '\0' && serviceDesc != nullptr && serviceDesc[0] != '\0')
        {
            strcpy(m_licencePlate, plateNo);
            m_makeModel = new char[strlen(carMakeModel) + 1];
            strcpy(m_makeModel, carMakeModel);
            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_serviceDesc, serviceDesc);
            m_cost = serviceCost;
        }
        else
        {
            setEmpty();
        }
    }


    void Car::display() const {
        if (m_licencePlate[0] != '\0' && m_makeModel && m_serviceDesc) {
            cout << left << setw(15) << "License Plate: " << right << setw(20) << m_licencePlate << endl;
            cout << left << setw(15) << "Model: " << right << setw(20) << (m_makeModel ? m_makeModel : "") << endl;
            cout << left << setw(15) << "Service Name: " << right << setw(20) << (m_serviceDesc ? m_serviceDesc : "") << endl;
            cout << left << setw(15) << "Service Cost: " << fixed << setprecision(2) << right << setw(20) << m_cost << endl;
        }
    }
}