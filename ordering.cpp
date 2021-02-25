#include <ordering.hpp>

int main(int argc, char **argv) {
    validateArguments(argc, argv);
    vector<string> lines = readInput(argc, argv);
    vector<Customer> customers;
    vector<Order> orders;

    for (vector<string>::const_iterator i = lines.begin(); i != lines.end(); i++)
    {
        cout << *i << "\n";
        string line = *i;
        switch(line.front()) {
            // New customer
            case 'C':
                customers.push_back(Customer(stoi (line.substr(1, 4)),
                                                   line.substr(5, 44)));
                break;
            // New sale
            case 'S':
                orders.push_back(Order(stoi(line.substr(1, 8)),
                                       line.at(9),
                                       stoi(line.substr(10, 13)),
                                       stoi(line.substr(14, 16))));
                break;
            // End-of-day
            case 'E':
                break;
        }
    }

    cout << customers[0].id << customers[0].name << "\n";
    cout << customers[1].id << customers[1].name << "\n";
    cout << customers[2].id << customers[2].name << "\n";

    cout << orders[0].date + " " << orders[0].type + " " << orders[0].customerNumber + " " << orders[0].quantity + " " << "\n";

    return 0;
}
