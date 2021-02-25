#include <ordering.hpp>

int main(int argc, char **argv) {
    validateArguments(argc, argv);
    vector<string> lines = readInput(argc, argv);
    unordered_map<int, Customer> customers;
    vector<Order> orders;

    for (vector<string>::const_iterator i = lines.begin(); i != lines.end(); i++)
    {
        string line = *i;
        switch(line.front()) {
            // New customer
            case 'C':
            {
                int customerID = stoi(line.substr(1, 4));
                Customer newCustomer = Customer(customerID, line.substr(5, 39));
                customers.insert({ customerID, newCustomer });
                cout << "New Customer: " << customers.at(customerID).name << "\n";
                break;
            }
            // New sale
            case 'S':
            {
                orders.push_back(Order(stoi(line.substr(1, 8)),
                                       line.at(9),
                                       stoi(line.substr(10, 4)),
                                       stoi(line.substr(14, 3))));
                cout << "New Order for customer: " << stoi(line.substr(10, 4)) << "\n";
                if (line.at(9) == 'X')
                    orders[3].ship();
                break;
            }
            // End-of-day
            case 'E':
            {
                cout << "End-of-day" << "\n";
                break;

            }
        }
    }

    cout << orders[0].date << " " << orders[0].type << " " << orders[0].customerNumber << " " << orders[0].quantity << "\n";
    cout << orders[1].date << " " << orders[1].type << " " << orders[1].customerNumber << " " << orders[1].quantity << "\n";
    cout << orders[2].date << " " << orders[2].type << " " << orders[2].customerNumber << " " << orders[2].quantity << "\n";

    return 0;
}
