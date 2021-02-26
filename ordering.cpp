#include <ordering.hpp>

int main(int argc, char **argv) {
    validateArguments(argc, argv);
    vector<string> lines = readInput(argc, argv);
    customerMap customers;
    vector<Order> orders;

    for (vector<string>::const_iterator i = lines.begin(); i != lines.end(); ++i)
    {
        string line = *i;
        switch(line.front()) {
            // New customer
            case 'C':
                addCustomer(line, customers);
                break;
            // New order
            case 'S':
                addOrder(line, orders);
                break;
            // End-of-day
            case 'E':
                endDay(line, customers, orders);
                break;
        }
    }

    return 0;
}

void addCustomer(string line, customerMap & customers)
{
    int customerID = stoi(line.substr(1, 4));
    Customer newCustomer = Customer(customerID, line.substr(5, 39));
    customers.insert({ customerID, newCustomer });
    cout << "OP: customer " << setfill('0') << std::setw(4) << customers.at(customerID).id << " added\n";
}

void addOrder(string line, vector<Order> & orders)
{
    orders.push_back(Order(stoi(line.substr(1, 8)),
                           line.at(9),
                           stoi(line.substr(10, 4)),
                           stoi(line.substr(14, 3))));
    string orderType = (orders.back().type == 'N' ? ": normal order: quantity " : ": EXPRESS order: quantity ");
    cout << "OP: customer " << setfill('0') << std::setw(4) << orders.back().customerID << orderType << orders.back().quantity << "\n";
}

void endDay(string line, customerMap & customers, vector<Order> & orders)
{
    cout << "OP: end of day " << line.substr(1, 8) << ":\n";
    for (auto& customer: customers)
    {
        cout << customer.first;
    }
}