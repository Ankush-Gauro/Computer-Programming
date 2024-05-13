/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-01-27
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"
#include <cstring>
using namespace std;
namespace seneca {

    bool read(int& value, FILE* fptr) {
        std::fscanf(fptr, "%d\n", &value);
        if (value) {
            return 1;
        }
        else {
            return 0;
        }
    }


    bool read(double& value, FILE* fptr) {
        int res = fscanf(fptr, "%lf", &value);
        if (res != 1) {
            return false;
        }
        else {
            return res;
        }
    }



    bool read(char* cstr, FILE* fptr) {
        std::fscanf(fptr, ",%60[^\n]\n", cstr);
        if (cstr) {
            return 1;
        }
        else {
            return 0;
        }
    }



    bool read(Assessment& assess, FILE* fptr) {
        bool success = false;
        double tempMark;
        char tempTitle[61];
        if (read(tempMark, fptr) && read(tempTitle, fptr)) {
            assess.m_mark = new double;
            assess.m_title = new char[strlen(tempTitle) + 1];
            *assess.m_mark = tempMark;
            strcpy(assess.m_title, tempTitle);
            success = true;
        }
        return success;
    }

    void freeMem(Assessment*& aptr, int size) {
        for (int i = 0; i < size; i++) {
            delete aptr[i].m_mark;
            delete[] aptr[i].m_title;
        }
        delete[] aptr; 
        aptr = nullptr;
    }

    int read(Assessment*& aptr, FILE* fptr) {
        int numRecords;
        if (read(numRecords, fptr) != true) {
            return 0;
        }

        aptr = new Assessment[numRecords];

        int count = 0;
        for (int i = 0; i < numRecords; ++i) {
            if (read(aptr[i], fptr)) {
                ++count;
            }
            else {
                break;
            }
        }

        if (count != numRecords) {
            freeMem(aptr, count);
            return 0;
        }

        return count;
    }





}