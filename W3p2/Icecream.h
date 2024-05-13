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

#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H

namespace seneca {
    class icecream {
        const double vanillaPrice = 5.00;
        const int scoopPrice = 5;
        const int vanillaTextSize = 4;

        int m_iceCreamFlavour;
        int m_numOfScoops;
        double m_price = 0.00;
        char m_vanillaWafeCone[4];

    public:
        void getOrder();
        void printOrder();
        int Price();
    };
}

#endif
