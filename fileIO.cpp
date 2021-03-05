#include "fileIO.hpp"

/*
    This file contains functions that handles the reading and writing to input
    parameter and output text files.
*/

void validateArguments(int argc, char **argv)
{
    /* Check the number of parameters is valid */
    if (argc != 2)
    {
        fprintf(stderr, "Invalid number of arguments.\n");
        exit(1);
    }
}

bool isValidLine(string line)
{
    // Check length of line
    if (line.length() > 45)
        return false;

    // Check first character and its following parameters
    switch(line.front()) 
    {
        // New customer
        case 'C':
        {
            string customerID = line.substr(1, 4);
            return !customerID.empty() &&
                    std::all_of(customerID.begin(), customerID.end(), ::isdigit);
            break;
        }
        // New order
        case 'S':
        {
            string date = line.substr(1, 8);
            char type = line.at(9);
            string customerID = line.substr(10, 4);
            string orderQuantity = line.substr(14, 3);
            return (!date.empty() && std::all_of(date.begin(), date.end(), ::isdigit)) ||
                   (type == 'N' || type == 'X') ||
                   (!customerID.empty() && std::all_of(customerID.begin(), customerID.end(), ::isdigit)) ||
                   (!orderQuantity.empty() && std::all_of(orderQuantity.begin(), orderQuantity.end(), ::isdigit));
            break;
        }
        // End-of-day
        case 'E':
        {
            string date = line.substr(1, 8);
            return !date.empty() &&
                    std::all_of(date.begin(), date.end(), ::isdigit);
            break;
        }
        default:
        {
            if (!line.empty())
                return false;
        }
    }
    return true;
}

/*
    Function: readInput
    ---------------------------------------------------------------------------
    Checks all user inputs to the program are valid.

    argc:    number of command-line arguments passed by the user
    argv:    array of character pointers listing all the arguments

    returns: null
*/
vector<string> readInput(int argc, char **argv)
{
    vector<string> lines;

    ifstream inputFile;
    inputFile.exceptions ( ifstream::badbit );
    try {
        ifstream inputFile(argv[1]);
        string line; 
        while (!inputFile.eof())
        {
            string line;
            getline(inputFile, line);
            if (isValidLine(line))
            {
                lines.push_back(line);
            }
            else
            {
                cout << "Invalid line in input file:\n" << line << "\n";
                exit(1);
            }
        }
    }
    catch (const ifstream::failure& e) {
        cout << "Error opening or reading file\n";
    }

    inputFile.close();
    return lines;
}
