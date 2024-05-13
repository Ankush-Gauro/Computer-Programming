/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-02-01
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guest.h"
using namespace std;
namespace seneca {

    struct Room {
        char m_roomNumber[6];
        int m_noOfGuests;
        Guest* m_guests;
    };

    void set(Room& room, int numberOfGuests, const char* roomNumber)
    {
        strncpy(room.m_roomNumber, roomNumber, sizeof(room.m_roomNumber));
        room.m_noOfGuests = numberOfGuests;
        room.m_guests = new Guest[numberOfGuests];
        int i;
        for (i = 0; i < room.m_noOfGuests; i++) {
            room.m_guests[i].m_firstname = nullptr;
            room.m_guests[i].m_lastname = nullptr;
        }

    }

    void print(const Room& room) {
    if (room.m_noOfGuests == 0) {
        cout << "Empty Room!" << endl;
    }
    else {
        cout << "Room Number: " << room.m_roomNumber << endl;
        for (int i = 0; i < room.m_noOfGuests; ++i) {
            cout << "    ";
            print(room.m_guests[i]);
        }
    }
}

   
    void book(Room& room) {
        int numberOfGuests;
        char roomNumber[6];

        cout << "Room number: ";
        cin >> roomNumber;
        cout << "Number of guests: ";
        cin >> numberOfGuests;
        set(room, numberOfGuests, roomNumber);
        for (int i = 0; i < numberOfGuests; ++i) {
            cout << i + 1 << ":" << endl;
            book(room.m_guests[i]);
        }
    }

    void vacate(Room& room) {
        for (int i = 0; i < room.m_noOfGuests; ++i) {
            vacate(room.m_guests[i]);
        }
        delete[] room.m_guests;
        room.m_noOfGuests = 0;
        room.m_guests = nullptr;
        room.m_roomNumber[0] = '\0';
    }
}


