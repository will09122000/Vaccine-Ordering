#include <customer.hpp>

int Customer::getId()
{
    return this->id;
}

int Customer::getQuantity()
{
    return this->orderQuantity
}

void Customer::setOrderQuantity(int orderQuantity)
{
    this->orderQuantity = orderQuantity;
}

void Customer::addInvoice(Invoice invoice)
{
    this->invoices.push_back(invoice);
}

void Customer::printInvoice()
{
    Invoice invoice = this->invoices.back();
    cout << "SC: customer " << setfill('0') << setw(4) << this->id
         << ": invoice " << invoice.getId() << ": date " << invoice.getDate()
         << ": quantity " << invoice.getQuantity() << "\n";
}

Customer::Customer(int id, string name)
{
    this->id = id;
    this->name = name;
}
