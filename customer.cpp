#include <customer.hpp>

//Getters

int Customer::getId()
{
    return this->id;
}

int Customer::getQuantity()
{
    return this->orderQuantity;
}

// Setters

void Customer::setQuantity(int orderQuantity)
{
    this->orderQuantity = orderQuantity;
}

/*
    Method: addInvoice
    ---------------------------------------------------------------------------
    Adds an invoice to the vector of customer invoices.

    invoice: the invoice to be added

    returns: null
*/
void Customer::addInvoice(Invoice invoice)
{
    this->invoices.push_back(invoice);
}

/*
    Method: printInvoice
    ---------------------------------------------------------------------------
    Prints the details of the latest customer invoice.

    returns: null
*/
void Customer::printInvoice()
{
    Invoice invoice = this->invoices.back();
    cout << "SC: customer " << setfill('0') << setw(4) << this->id
         << ": invoice " << invoice.getId() << ": date " << invoice.getDate()
         << ": quantity " << invoice.getQuantity() << "\n";
}

// Constructors

Customer::Customer(int id, string name)
{
    this->id = id;
    this->name = name;
}
