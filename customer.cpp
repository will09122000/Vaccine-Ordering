#include <customer.hpp>

class Customer
{
    private:
        int id;
        string name;
        int orderQuantity = 0;
        vector<Invoice> invoices;

    public:
        // getters
        int getId()
        {
            return this->id;
        }

        // methods
        void addInvoice(Invoice invoice)
        {
            this->invoices.push_back(invoice);
        }

        void printInvoice()
        {
            Invoice invoice = this->invoices.back();
            cout << "SC: customer " << setfill('0') << setw(4) << this->id << ": invoice " << invoice.getId() << ": date " << invoice.getDate() << ": quantity " << invoice.getQuantity() << "\n";
        }

        Customer(int id, string name)
        {
            this->id = id;
            this->name = name;
        }
};
