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

#include <iostream>
#include "Icecream.h"
#include "Vendor.h"
using namespace std;
namespace seneca {

    void Vendor::setEmpty() {
        icecreams = nullptr;
        numberOfOrders = 0;
        totalPrice = 0;
        tax = 0;
    }

    void Vendor::takeOrders() {
        clearData();

        cout << "Seneca Icecream shop" << endl;

        cout.width(11);
        cout << right << "@" << endl;

        cout.width(13);
        cout << right << "(' .)" << endl;

        cout.width(14);
        cout << right << "(*.`. )" << endl;

        cout.width(13);
        cout << right << "\\###/" << endl;

        cout.width(12);
        cout << right << "\\#/" << endl;

        cout.width(11);
        cout << right << "V" << endl;

        cout << "How many Icecreams?" << endl;
        cout << "> ";

        cin >> numberOfOrders;

        icecreams = new icecream[numberOfOrders];

        for (int i = 1; i <= numberOfOrders; ++i) {
            cout << "Order number " << i << ":" << endl;
            icecreams[i - 1].getOrder();
        }
    }


    void Vendor::displayOrders() {

        cout << endl << "********** Order Summary **********" << endl;

        for (int i = 1; i <= numberOfOrders; ++i) {
            cout << "Order No: " << (i) << ":" << endl;
            icecreams[i - 1].printOrder();
            if (i == numberOfOrders) {
                ;
            }
            else {
                cout << endl;
            }
        }

        totalPrice = 0;
        for (int i = 1; i <= numberOfOrders; ++i) {
            totalPrice += icecreams[i - 1].Price();
        }

        tax = totalPrice * 0.13;

        cout << "-----------------------------------" << endl;
        cout.width(30);
        cout << left << "Price:";
        cout << right << totalPrice << endl;

        cout.width(31);
        cout << left << "Tax:";
        cout << right << tax << endl;

        cout.width(30);
        cout << left << "Total Price ($):";
        cout << right << totalPrice + tax << endl;
    }

    void Vendor::clearData() {
        delete[] icecreams;
        numberOfOrders = 0;
        totalPrice = 0;
        tax = 0;
    }

}