#include <ordering.hpp>

int main(int argc, char **argv) {
    validateArguments(argc, argv);
    vector<string> lines = readInput(argc, argv);

    for (vector<string>::const_iterator i = lines.begin(); i != lines.end(); i++)
    {
        cout << *i << "\n";
        string line = *i;
        switch(line.front()) {
            case 'C':
                cout << line.front() << "\n";
                break;
            case 'S':
                cout << line.front() << "\n";
                break;
            case 'E':
                cout << line.front() << "\n";
                break;
        }
    }

    customer testCustomer;
    testCustomer.id = 1;

    order testOrder;
    testOrder.id = 1000;

    cout << testCustomer.id << testOrder.id << "\n";

    return 0;
}