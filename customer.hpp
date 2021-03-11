#include <string>
#include <vector>
#include <invoice.cpp>

using namespace std;

/*
    This class represents a single customer in the system.
*/
class Customer
{
    int id;
    string name;
    int orderQuantity = 0;
    vector<Invoice> invoices;

    public:
        // Getters
        int getId();
        int getQuantity();

        // Setters
        void setQuantity(int orderQuantity);

        // Methods
        void addInvoice(Invoice invoice);
        void printInvoice();

        // Constructors
        Customer(int id, string name);
};
