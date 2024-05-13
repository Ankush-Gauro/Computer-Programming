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
#include <limits>
#include <iomanip>
#include <cstring>
#include "Icecream.h"
using namespace std;

namespace seneca {

    void icecream::getOrder() {
        cout << "Select flavour:" << endl;
        cout << "----------------" << endl;
        cout << "1: Chocolate" << endl;
        cout << "2: Strawberry" << endl;
        cout << "3: Mango" << endl;
        cout << "4: Tutti fruit" << endl;
        cout << "5: Almond crunch" << endl;
        cout << "----------------" << endl;

        while (true) {
            cout << "> ";
            cin >> m_iceCreamFlavour;

            if (m_iceCreamFlavour >= 1 && m_iceCreamFlavour <= 5) {
                break;
            }

            else if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry, retry" << endl;
            }

            else if (m_iceCreamFlavour < 1 || m_iceCreamFlavour > 5) {
                cout << "Invlid value(1<=val<=5)" << endl;
            }
        }

        cout << "Number of Scoops (max 3)" << endl;

        while (true) {
            cout << "> ";
            cin >> m_numOfScoops;

            if (m_numOfScoops >= 1 && m_numOfScoops <= 3) {
                break;
            }

            else if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry, retry" << endl;
            }

            else if (m_numOfScoops < 1 || m_numOfScoops > 3) {
                cout << "Invlid value(1<=val<=3)" << endl;
            }
        }

        cout << "Vanilla wafer cone?" << endl;
        cout << "(Y)es/(N)o > ";
        cin >> m_vanillaWafeCone;

        while (true) {
            if (
                strcmp(m_vanillaWafeCone, "Y") == 0 ||
                strcmp(m_vanillaWafeCone, "y") == 0 ||
                strcmp(m_vanillaWafeCone, "N") == 0 ||
                strcmp(m_vanillaWafeCone, "n") == 0
                ) {
                break;
            }
            else {
                cout << "Only Y or N are acceptable:" << endl;
                cout << "> ";
                cin >> m_vanillaWafeCone;
            }
        }
    }

    void icecream::printOrder() {
        cout << "Order details:                Price" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Number of scoops, " << m_numOfScoops << " total:";
        cout.width(9);
        cout << right << fixed << setprecision(2) << double(m_numOfScoops * scoopPrice) << endl;
        m_price += double(m_numOfScoops * scoopPrice);

        switch (m_iceCreamFlavour) {
        case 1:
            cout << "Chocolate flavour: ";
            cout.width(16);
            cout << right << fixed << setprecision(2) << double(m_numOfScoops) << endl;
            m_price += double(m_numOfScoops);
            break;
        case 2:
            cout << "Strawberry flavour" << endl;
            break;
        case 3:
            cout << "Mango flavour" << endl;
            break;
        case 4:
            cout << "Tutti fruit flavour" << endl;
            break;
        case 5:
            cout << "Almond crunch flavour" << endl;
            break;
        }

        if (m_vanillaWafeCone[0] == 'y') {
            cout << "Vanilla Wafer:";
            cout.width(21);
            cout << right << fixed << setprecision(2) << vanillaPrice << endl;
            m_price += vanillaPrice;
        }
        else {
            cout << "Vanilla Wafer:";
            cout.width(21);
            cout << right << fixed << setprecision(2) << double(0) << endl;
        }

        cout << "Price:";
        cout.width(29);
        cout << right << fixed << setprecision(2) << m_price << endl;
    }

    int icecream::Price() {
        return m_price;
    }

}
