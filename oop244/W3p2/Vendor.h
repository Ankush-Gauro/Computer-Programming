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

#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H
#include "Icecream.h" 
#define _CRT_SECURE_NO_WARNINGS
namespace seneca {


	class Vendor {
	private:
		icecream* icecreams;
		int numberOfOrders;
		double totalPrice;
		double tax;

	public:
		void setEmpty();
		void takeOrders();
		void displayOrders();
		void clearData();
	};
}

#endif