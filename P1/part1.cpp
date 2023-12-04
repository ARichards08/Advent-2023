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

int cal_sum=0, first_digit_pos, second_digit_pos, pos;
bool first_digit_found;
std::string first_digit, second_digit;

for(int i=0; i<cal_values.size(); i++){
    first_digit_found=false;
    for(int j=0; j<cal_values[i].length(); j++){

        // Finds first and last digits
        if (std::isdigit(cal_values[i][j]) && first_digit_found==false){
            first_digit=cal_values[i][j];
            first_digit_pos=j;
            second_digit=cal_values[i][j];
            second_digit_pos=j;
            first_digit_found=true;
        } else if (std::isdigit(cal_values[i][j])){
            second_digit=cal_values[i][j];
            second_digit_pos=j;
        };
    };

    cal_sum+=std::stoi(first_digit+second_digit);
};

std::cout << cal_sum << std::endl;

}