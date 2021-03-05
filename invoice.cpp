#include <invoice.hpp>

int Invoice::getId()
{
    return this->id;
}

int Invoice::getDate()
{
    return this->date;
}

int Invoice::getQuantity()
{
    return this->quantity;
}

Invoice::Invoice(int invoiceNumber, int customerID, int date, int quantity)
{
    this->id = invoiceNumber;
    this->customerID = customerID;
    this->date = date;
    this->quantity = quantity;
}
