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

std::vector<std::string> digits{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::vector<int> first_word_pos, second_word_pos;

int k=1;
std::map<std::string, std::string> digits_ID;
for(const auto& d : digits){
    digits_ID[d]=std::to_string(k++);
};

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

    // Finds first and last words
    first_word_pos={INT_MAX, 0};
    second_word_pos={0, 0};
    for(int j=0; j<digits.size(); j++){
        pos=cal_values[i].find(digits[j]);

        if(pos < first_word_pos[0] && ){
            first_word_pos={pos, j};
        };
        if(pos > second_word_pos[0] && ){
            second_word_pos={pos, j};
        };

    };

    // Work out if the first word is before the first digit, and if the second word is after the second digit
    if(first_word_pos[0] < first_digit_pos){
        first_digit=digits_ID[digits[first_word_pos[1]]];
    };

    if(second_word_pos[0] > second_digit_pos){
        second_digit=digits_ID[digits[second_word_pos[1]]];
    };
    std::cout << std::stoi(first_digit+second_digit) << std::endl;
    cal_sum+=std::stoi(first_digit+second_digit);
};

std::cout << cal_sum << std::endl;

}