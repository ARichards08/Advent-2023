// Included packages
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>

// Classes

// Functions

// Program
int main() {


/////////////
// File input


std::string line;
std::vector<std::string> cal_values;

// Open input file
std::ifstream inputfile;
inputfile.open("input.txt", std::ios::in);

// Read file into array
while(true){
    std::getline(inputfile, line);
    if(!inputfile) break; // test eof to break

    cal_values.push_back(line);
};

// Close input file
inputfile.close();

//////////////
// Calculation



}