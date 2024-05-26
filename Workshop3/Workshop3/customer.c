#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "customer.h"

bool ValidPostalCode(const char* postal_code) {
    int i = 0;
    char formatted_postal_code[MAX];

    for (int j = 0; postal_code[j] != '\0'; j++) {
        if (!isspace(postal_code[j])) {
            formatted_postal_code[i] = toupper(postal_code[j]);
            i++;
        }
    }
    formatted_postal_code[i] = '\0';

    if (strlen(formatted_postal_code) != 6)
        return false;

    for (int j = 0; j < 6; j++) {
        if ((j % 2 == 0 && !isalpha(formatted_postal_code[j])) ||
            (j % 2 == 1 && !isdigit(formatted_postal_code[j])))
            return false;
    }

    return true;
}

void ToUppercase(char* str) {
    str[0] = toupper(str[0]);
    str[2] = toupper(str[2]);
    str[5] = toupper(str[5]);
}

Customer CustomerInfo() {
    Customer customer;

    printf("Enter first name: ");
    while (fgets(customer.firstName, MAX, stdin)) {
        if (customer.firstName[0] != '\n') {
            customer.firstName[strlen(customer.firstName) - 1] = '\0';
            break;
        }
        printf("Invalid Entry: ");
    }

    printf("Enter last name: ");
    while (fgets(customer.lastName, MAX, stdin)) {
        if (customer.lastName[0] != '\n') {
            customer.lastName[strlen(customer.lastName) - 1] = '\0';
            break;
        }
        printf("Invalid Entry: ");
    }

    printf("Enter address: ");
    while (fgets(customer.streetAddress, MAX, stdin)) {
        if (customer.streetAddress[0] != '\n') {
            customer.streetAddress[strlen(customer.streetAddress) - 1] = '\0';
            break;
        }
        printf("Invalid Entry: ");
    }

    printf("Enter city name: ");
    while (fgets(customer.city, MAX, stdin)) {
        if (customer.city[0] != '\n') {
            customer.city[strlen(customer.city) - 1] = '\0';
            break;
        }
        printf("Invalid Entry: ");
    }

    printf("Enter province name: ");
    while (fgets(customer.province, MAX, stdin)) {
        if (customer.province[0] != '\n') {
            customer.province[strlen(customer.province) - 1] = '\0';
            break;
        }
        printf("Invalid Entry: ");
    }

    printf("Enter postal code: ");
    while (fgets(customer.postalCode, MAX, stdin)) {
        if (ValidPostalCode(customer.postalCode)) {
            ToUppercase(customer.postalCode);
            break;
        }
        printf("Invalid Entry: ");
    }

    return customer;
}

void printCustomerInformation(const Customer* customer) {
    printf("\nYou entered:\n");
    printf("%s %s\n", customer->firstName, customer->lastName);
    printf("%s,\n", customer->streetAddress);
    printf("%s, %s,\n", customer->city, customer->province);
    printf("%s", customer->postalCode);
}

int main(void) {
    Customer customer = CustomerInfo();
    printCustomerInformation(&customer);

    return 0;
}

