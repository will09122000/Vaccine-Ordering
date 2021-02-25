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

/*
    Function: readInput
    ---------------------------------------------------------------------------
    Checks all user inputs to the program are valid.

    argc:    number of command-line arguments passed by the user
    argv:    array of character pointers listing all the arguments

    returns: null
*/
void readInput(int argc, char **argv)
{
    using namespace std;
    ifstream inputFile;
    inputFile.exceptions ( ifstream::badbit );
    try {
        std::ifstream file(argv[1]);
        std::string line; 
        while (std::getline(file, line))
        {
            cout << line;
        }
    }
    catch (const ifstream::failure& e) {
        cout << "Exception opening/reading file";
    }

    inputFile.close();
}
