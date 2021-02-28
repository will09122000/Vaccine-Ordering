#include <invoice.hpp>

class Invoice
{
    public:
        static int invoiceID;
        int customerID;
        int date;
        int quantity;

        Invoice(int invoiceNumber, int customerID, int date, int quantity)
        {
            this->invoiceID = invoiceNumber;
            this->customerID = customerID;
            this->date = date;
            this->quantity = quantity;
        }
};
