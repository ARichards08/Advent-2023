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

int sum=0;

std::vector<std::string> digits{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int k=1;
std::map<std::string, std::string> digits_ID;
for(const auto& d : digits){
    digits_ID[d]=std::to_string(k++);
};

std::vector<std::string> numbers;
int ans=0;

for(int i=0; i<cal_values.size(); i++){
    numbers.clear();
    for(int j=0; j<cal_values[i].length(); j++){
        if (std::isdigit(cal_values[i][j])){
            numbers.push_back(std::string(1, cal_values[i][j]));
        };
        for (int k=0; k<digits.size(); k++){
            if (cal_values[i].rfind(digits[k], j) == j) numbers.push_back(digits_ID[digits[k]]);
        };
    };

    ans+=std::stoi(numbers[0]+numbers[numbers.size()-1]);
};
std::cout << ans << std::endl;
}