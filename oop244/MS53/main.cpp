/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-04-09
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */


/***********************************************************************
// OOP244 Project
//
// File  main.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "Utils.h"
using namespace std;
using namespace seneca;
void copyFile(const char* des, const char* src) {
    ifstream infile(src);
    ofstream outfile(des);
    if (outfile) {
        char ch;
        while (infile.get(ch)) {
            outfile.put(ch);
        }
    }
}
void displayFile(const char* fname) {
    ifstream fin(fname);
    char ch;
    cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
    while (fin.get(ch)) cout << ch;
    cout << "***************************************************" << endl << endl;
}
void theApp() {
    PreTriage P("smalldata.csv");
    P.run();
}
int main() {
    copyFile("smalldata.csv", "smalldata.csv.bak");
    seneca::debug = true;
    U.setDebugTime(8, 41);
    theApp();
    displayFile("smalldata.csv");
    return 0;
}