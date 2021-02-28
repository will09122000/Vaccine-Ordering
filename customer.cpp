#include <customer.hpp>

class Customer
{
    public:
        int id;
        string name;
        int orderQuantity = 0;
        vector<Invoice> invoices;

        void addInvoice(Invoice invoice)
        {
            this->invoices.push_back(invoice);
        }

        void printInvoice()
        {
            Invoice invoice = this->invoices.back()
            cout << "SC: customer " << setfill('0') << setw(4) << this->id << ": invoice " << invoice.id << ": date " << invoice.date << ": quantity " << invoice.quantity << "\n";
        }


        Customer(int id, string name)
        {
            this->id = id;
            this->name = name;
        }
};
