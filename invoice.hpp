#ifndef INVOICE
#define INVOICE
#include <iostream>
#include <iomanip>
#endif

/*
    This class represents a single invoice in the system.
*/
class Invoice
{
    int id;
    int customerID;
    int date;
    int quantity;

    public:
        // Getters
        int getId();
        int getDate();
        int getQuantity();

        // Constructors
        Invoice(int invoiceNumber, int customerID, int date, int quantity);
};
