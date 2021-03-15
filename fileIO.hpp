#ifndef FILEIO
#define FILEIO
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <fstream>
#include <bits/stdc++.h>
#endif

using namespace std;

void validateArguments(int argc, char **argv);
bool isValidLine(string line);
vector<string> readInput(int argc, char **argv);
