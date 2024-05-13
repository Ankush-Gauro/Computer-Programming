/*
-----------------------------------------------------------------------------
 Author      : Ankush Gauro
 Email       : agauro@myseneca.ca
 Student Id  : 108593237
 Section     : ZCC
 Date		 : 2024-01-25
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------------------------
 */
#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H
namespace seneca {

    /// <summary>
    /// Record of a mark received by a student.
    /// </summary>
    struct StMark {
        char name[21];
        char surname[31];
        int mark;
    };

    bool printReport(const char* filename);

}
#endif // !SENECA_STMARK_H

