#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char firstName[MAX];
    char lastName[MAX];
    char streetAddress[MAX];
    char city[MAX];
    char province[MAX];
    char postalCode[MAX];
} Customer;

bool ValidPostalCode(const char* postal_code);
void ToUppercase(char* str);
Customer CustomerInfo();
void printCustomerInformation(const Customer* customer);

#endif 
