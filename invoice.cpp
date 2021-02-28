#include <invoice.hpp>

class Invoice
{
    private:
        int id;
        int customerID;
        int date;
        int quantity;

    public:
        Invoice(int invoiceNumber, int customerID, int date, int quantity)
        {
            this->id = invoiceNumber;
            this->customerID = customerID;
            this->date = date;
            this->quantity = quantity;
        }
};
