#include <ordering.hpp>

int main(int argc, char **argv)
{
    validateArguments(argc, argv);
    vector<string> lines = readInput(argc, argv);
    vector<Customer> customers;
    vector<Order> orders;
    int invoiceNumber = 1000;

    cout << "A" << "\n";

    for (vector<string>::const_iterator i = lines.begin(); i != lines.end(); ++i)
    {
        string line = *i;
        switch(line.front()) 
        {
            // New customer
            case 'C':
                addCustomer(line, customers);
                break;
            // New order
            case 'S':
                addOrder(line, orders, customers, invoiceNumber);
                if (orders.back().type == 'X')
                    sendOrder(orders.back().customerID, orders, invoiceNumber, customers);
                break;
            // End-of-day
            case 'E':
                endDay(line, customers, orders, invoiceNumber);
                break;
        }
        cout << "-------------------------------------------------------------------\n";
    }
    return 0;
}

void addCustomer(string line, vector<Customer> & customers)
{
    customers.push_back(Customer(stoi(line.substr(1, 4)), line.substr(5, 39)));
    cout << "OP: customer " << setfill('0') << setw(4) << customers.back().id << " added\n";
}

void addOrder(string line, vector<Order> & orders, vector<Customer> & customers, int & invoiceNumber)
{
    orders.push_back(Order(stoi(line.substr(1, 8)),
                           line.at(9),
                           stoi(line.substr(10, 4)),
                           stoi(line.substr(14, 3))));

    for (auto & customer: customers)
    {
        if (customer.id == stoi(line.substr(10, 4)))
        {
            customer.addInvoice(Invoice(invoiceNumber, stoi(line.substr(10, 4)), stoi(line.substr(1, 8)), stoi(line.substr(14, 3))));
        }
    }

    string orderType = (orders.back().type == 'N' ? ": normal order: quantity " : ": EXPRESS order: quantity ");
    cout << "OP: customer " << setfill('0') << setw(4) << orders.back().customerID << orderType << orders.back().quantity << "\n";
}

void sendOrder(int customerID, vector<Order> & orders, int & invoiceNumber, vector<Customer> & customers)
{
    int totalOrderQuantity = 0;
    int size = orders.size();
    int date;
    for (int i = 0; i < size; ++i)
    {
        if (orders[i].customerID == customerID)
        {
            totalOrderQuantity += orders[i].quantity;
            date = orders[i].date;
            orders.erase(orders.begin() + i);
        }
        if (size != (int)orders.size())
        {
            --i;
            size = orders.size();
        }
    }

    for (auto & customer: customers)
    {
        if (customer.id == customerID && totalOrderQuantity > 0)
        {
            customer.printInvoice();
        }
    }

    if (totalOrderQuantity > 0)
    {
        cout << "OP: customer " << setfill('0') << setw(4) << customerID << ": shipped quantity " << totalOrderQuantity << "\n";
    }
    invoiceNumber++;
}

void endDay(string line, vector<Customer> & customers, vector<Order> & orders, int & invoiceNumber)
{
    string date = line.substr(1, 8);
    cout << "OP: end of day " << date << "\n";
    for (auto const& customer: customers)
    {
        sendOrder(customer.id, orders, invoiceNumber, customers);
    }
}
