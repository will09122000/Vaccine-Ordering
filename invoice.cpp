#include <invoice.hpp>

class Invoice
{
    private:
        int id;
        int customerID;
        int date;
        int quantity;

    public:
        // getters
        int getId()
        {
            return this->id;
        }

        int getDate()
        {
            return this->date;
        }

        int getQuantity()
        {
            return this->quantity;
        }

        Invoice(int invoiceNumber, int customerID, int date, int quantity)
        {
            this->id = invoiceNumber;
            this->customerID = customerID;
            this->date = date;
            this->quantity = quantity;
        }
};
