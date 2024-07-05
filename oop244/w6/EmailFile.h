/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-03-12
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */

/***********************************************************************
// OOP244 Workshop # 6
//
// File:	EmailFile.h
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca {

	const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record

	class EmailFile;
	class Email
	{
		char* m_email{ nullptr };
		char* m_name{ nullptr };
		char m_year[5]{ '\0' };
		Email() {};
		Email& operator=(const Email&);
		bool load(std::ifstream& in);
		~Email();
		// Prohibit the copy constructor for this class: 
		Email(const Email&);
		// Make the EmailFile class a "friend" of the Email class
		friend class EmailFile;
	};


	class EmailFile
	{
		Email* m_emailLines{ nullptr };
		char* m_filename{};
		int m_noOfEmails{ 0 };
		void setFilename(const char* filename);
		void setEmpty();
		bool setNoOfEmails();


	public:
		// Constructors
		EmailFile();
		EmailFile(const char* filename);
		// Copy-Constructor
		EmailFile(const EmailFile& other);
		~EmailFile(); // Destructor

		void loadEmails();

		// Type-conversion overloads
		operator bool()const;

		void operator=(const EmailFile& other);
		bool saveToFile(const char* filename) const;
		std::ostream& view(std::ostream& ostr) const;
		void fileCat(const EmailFile& obj, const char* name = nullptr);
	};

	std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);

}
#endif // !SENECA_EMAILFILE_H
