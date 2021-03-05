#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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