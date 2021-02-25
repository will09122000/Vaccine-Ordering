#include <ordering.hpp>

int main(int argc, char **argv) {
    validateArguments(argc, argv);
    vector<string> lines = readInput(argc, argv);

    for (std::vector<string>::const_iterator i = lines.begin(); i != lines.end(); ++i)
    std::cout << *i << "\n";

    customer testCustomer;
    testCustomer.myNum = 10;

    return 0;
}