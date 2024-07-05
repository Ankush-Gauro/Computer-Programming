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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace seneca {
    const int MAX_PATIENT_NUM = 100;

    PreTriage::PreTriage(const char* dataFilename) :m_ContagionWaitTime{ 15 }, m_TriageWaitTime{ 5 }{
        if (dataFilename && dataFilename[0]) {
            strcpy(m_dataFilename, dataFilename);
            m_numPatients = 0;
            load();
        }
    }

    PreTriage::~PreTriage(){
        save();
        for (int i = 0; i < m_numPatients; ++i) {
            delete m_lineup[i];
        }
    }

    Time PreTriage::getWaitTime(const Patient& patient) const {
        char type = patient.type();
        int count = 0;
        for (int i = 0; i < m_numPatients; ++i) {
            if (m_lineup[i]->type() == type) {
                ++count;
            }
        }
        Time waitTime = (type == 'C') ? m_ContagionWaitTime : m_TriageWaitTime;
        waitTime *= count;
        return waitTime;
    }

    void PreTriage::setAverageWaitTime(Patient& patient) {
        Time currentTime = U.getTime();
        Time patientTicketTime = patient.time();
        Time& averageWaitTime = (patient.type() == 'C') ? m_ContagionWaitTime : m_TriageWaitTime;
        int ticketNumber = patient.number();
        averageWaitTime = ((currentTime - patientTicketTime) + (averageWaitTime * (ticketNumber - 1))) / ticketNumber;
    }

    int PreTriage::indexOfFirstInLine(char type) const {
        int retVal = -1;
        for (int i = 0; i < m_numPatients && retVal == -1; ++i) {
            if (m_lineup[i]->type() == type) {
                retVal = i;
            }
        }
        return retVal;
    }

    void PreTriage::load() {
        bool retVal = true;
        ifstream file(m_dataFilename);
        cout << "Loading data..." << endl;
        if (!file.is_open()) {
            cerr << "No data or bad data file!\n\n";
            return;
        }
        file >> m_ContagionWaitTime;
        file.ignore();
        file >> m_TriageWaitTime;
        file.ignore();
        char type;
        while (m_numPatients < MAX_PATIENT_NUM && file >> type) {
            file.ignore();
            Patient* patient = nullptr;
            if (type == 'C') {
                patient = new TestPatient;
            }
            else if (type == 'T') {
                patient = new TriagePatient;
            }
            if (patient) {
                patient->read(file);
                m_lineup[m_numPatients++] = patient;
            }
        }
        if (m_numPatients == MAX_PATIENT_NUM && file.peek() != EOF) {
            cout << "Warning: number of records exceeded " << MAX_PATIENT_NUM << endl;
        }
        if (m_numPatients == 0) {
            cout << "No data or bad data file!\n\n";
            retVal = false;
        }
        if (retVal == true) cout << m_numPatients << " Records imported..." << endl << endl;
    }

    void PreTriage::registerPatient()
    {
        Menu m("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
        int choice;
        if (m_numPatients < 100) {
            m.display();
            cin >> choice;
            cin.ignore(1000, '\n');
            switch (choice) {
            case 0:
                break;
            case 1:
                m_lineup[m_numPatients] = new TestPatient;
                cout << "Please enter patient information: " << endl;
                cin.clear();
                cin >> *m_lineup[m_numPatients];
                m_lineup[m_numPatients]->setArrivalTime();
                cout << "\n******************************************\n";
                cout << *m_lineup[m_numPatients];
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_numPatients]);
                cout << "\n******************************************\n\n";
                ++m_numPatients;
                break;
            case 2:
                m_lineup[m_numPatients] = new TriagePatient;
                cout << "Please enter patient information: " << endl;
                cin.clear();
                cin >> *m_lineup[m_numPatients];
                m_lineup[m_numPatients]->setArrivalTime();
                cout << "\n******************************************\n";
                cout << *m_lineup[m_numPatients];
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_numPatients]);
                cout << "\n******************************************\n\n";
                ++m_numPatients;

                break;
            }
        }
        else {
            cout << "Line up full!\n";
        }
    }

    void PreTriage::admit()
    {
        int choice, idx;
        Menu m("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
        Time t = U.getTime();
        m.display();
        cin >> choice;
        cout << "\n******************************************\n";
        switch (choice) {
        case 0:
            break;
        case 1:
            idx = indexOfFirstInLine('C');
            if (idx != -1) {
                cout << "Call time: [" << t << "]" << endl;
                cout << "Calling at for " << *m_lineup[idx];
                setAverageWaitTime(*m_lineup[idx]);
                removeDynamicElement(m_lineup, idx, m_numPatients);
            }
            else {
                cout << "Lineup is empty!\n";
            }
            break;
        case 2:
            idx = indexOfFirstInLine('T');
            if (idx != -1) {
                cout << "Call time: [" << t << "]" << endl;
                cout << "Calling at for " << *m_lineup[idx];
                setAverageWaitTime(*m_lineup[idx]);
                removeDynamicElement(m_lineup, idx, m_numPatients);
            }
            else {
                cout << "Lineup is empty!\n";
            }
            break;
        }
        cout << "******************************************\n\n";
    }

    void PreTriage::save() const {
        ofstream file(m_dataFilename);
        cout << "Saving lineup...\n";
        if (!file.is_open()) {
            cerr << "Failed to open file for saving data!" << endl;
            return;
        }
        file << m_ContagionWaitTime << "," << m_TriageWaitTime << endl;
        int numContagion = 0, numTriage = 0;
        for (int i = 0; i < m_numPatients; ++i) {
            file << *m_lineup[i] << endl;

            if (m_lineup[i]->type() == 'C') ++numContagion;
            else if (m_lineup[i]->type() == 'T') ++numTriage;
        }
        cout << numContagion << " Contagion Tests and " << numTriage << " Triage records were saved!" << endl;
    }

    void PreTriage::lineup() const
    {
        Menu m("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
        int choice, counter = 1;
        m.display();
        cin >> choice;
        cout << "Row - Patient name                                          OHIP     Tk #  Time\n";
        cout << "-------------------------------------------------------------------------------\n";
        switch (choice) {
        case 0:
            break;

        case 1:
            for (int i = 0; i < m_numPatients && m_numPatients; ++i) {
                if (m_lineup[i]->type() == 'C') {
                    clog.setf(ios::left);
                    clog << counter++;
                    clog << "   - ";
                    m_lineup[i]->write(clog);
                    cout << endl;
                }
            }
            if (m_numPatients == 0) clog << "Line up is empty!\n";
            break;
        case 2:
            for (int i = 0; i < m_numPatients && m_numPatients; ++i) {
                if (m_lineup[i]->type() == 'T') {
                    clog.setf(ios::left);
                    clog << counter++;
                    clog.unsetf(ios::left);
                    clog << "   - ";
                    m_lineup[i]->write(clog);
                    clog << endl;
                }
            }
            if (m_numPatients == 0) clog << "Line up is empty!\n";
            break;
        }
        cout << "-------------------------------------------------------------------------------\n";
    }

    void PreTriage::run() {
        int choice;
        while (true) {
            Menu m("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
            m.display();
            cin >> choice;
            switch (choice) {
            case 0:
                return;
            case 1:
                registerPatient();
                break;
            case 2:
                admit();
                break;
            case 3:
                lineup();
                break;
            default:
                break;
            }
        }
    }
}
