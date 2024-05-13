/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-02-07
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

/***********************************************************************
// OOP244 Workshop #03 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date: September 28, 2023
// Author: Yosef Ashibani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Vendor.h"
#include "Icecream.h"
#include <iostream>
using namespace seneca;
int main() {
    Vendor vendor;
    vendor.setEmpty();
    vendor.takeOrders();
    vendor.displayOrders();
    vendor.clearData();
    return 0;
}