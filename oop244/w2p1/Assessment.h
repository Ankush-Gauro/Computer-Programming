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


#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H


#include <iostream>
namespace seneca {


	struct Assessment {
		double* m_mark;
		char* m_title;
	};

	bool read(int& value, FILE* fptr);

	bool read(double& value, FILE* fptr);

	bool read(char* cstr, FILE* fptr);

	bool read(Assessment& assess, FILE* fptr);

	void freeMem(Assessment*& aptr, int size);

	int read(Assessment*& aptr, FILE* fptr);
}

#endif