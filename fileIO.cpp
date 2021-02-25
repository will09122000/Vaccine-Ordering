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
            lines.push_back(line);
        }
    }
    catch (const ifstream::failure& e) {
        cout << "Error opening or reading file\n";
    }

    inputFile.close();
    return lines;
}
