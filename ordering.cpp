#include <ordering.hpp>

int main(int argc, char **argv) {
    validateArguments(argc, argv);
    vector<string> lines = readInput(argc, argv);
    vector<Customer> customers;

    for (vector<string>::const_iterator i = lines.begin(); i != lines.end(); i++)
    {
        cout << *i << "\n";
        string line = *i;
        switch(line.front()) {
            // New customer
            case 'C':
                cout << line.front() << "\n";
                customers.push_back(Customer(stoi (line.substr(2, 5)), line.substr(6, 45)));
                break;
            // New sale
            case 'S':
                cout << line.front() << "\n";
                break;
            // End-of-day
            case 'E':
                cout << line.front() << "\n";
                break;
        }
    }


    Order testOrder;
    testOrder.id = 1000;


    return 0;
}
