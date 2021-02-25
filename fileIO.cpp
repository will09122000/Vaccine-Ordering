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
    string lines[50];
    int counter = 0;
    ifstream inputFile;
    inputFile.exceptions ( ifstream::badbit );
    try {
        ifstream inputFile(argv[1]);
        string line; 
        while (!inputFile.eof())
        {
            //cout << line + "\n";
            getline(inputFile, lines[counter]);
            counter++;
        }
    }
    catch (const ifstream::failure& e) {
        cout << "Error opening or reading file\n";
    }

    for (int i=0; i < 50; i++) {
        if (!lines[i].empty()) { // print only if there is something in the current line
            cout << lines[i];
        }
    }

    inputFile.close();
}
