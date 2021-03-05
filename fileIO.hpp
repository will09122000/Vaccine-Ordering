#include <stdio.h>
#include <errno.h>
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std;

void validateArguments(int argc, char **argv);
bool isValidLine(string line);
vector<string> readInput(int argc, char **argv);
