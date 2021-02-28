#include <invoice.hpp>

class Invoice
{
    public:
        int id;
        int customerID;
        int date;
        int quantity;

        Invoice(int invoiceNumber, int customerID, int date, int quantity)
        {
            this->id = invoiceNumber;
            this->customerID = customerID;
            this->date = date;
            this->quantity = quantity;
        }
};
