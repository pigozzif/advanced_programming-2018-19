#include <iostream>
#include <string>


// Helper function for the first exercise

int test(int num) {
    return num;
}


// Exercise one

void errors() {
    std::c0ut << "Hello, world!"; // The error message is: c0ut is not a member of 'std'. Clearly, we are looking for a function
    // that has not been defined in that namespace.
    int first{0};
    std::cout << firs; // The error message is: 'firs' was not declared in this scope. Obviously, we are trying to access a symbol
    // which was not initialized in this scope (define by the innermost curly brackets).
    std::cout << "Hello, World!" // The error message is: expected ';' before '}' token. When this line of code was compiled,
    // it was followed by the end function }. Since in the C++ programming language indentation does not matter, the end of an
    // instruction is signalled through a semicolon ";".
    std::cout << "Hello, World!"; // The error message is: 'cout' is not a member of 'std'. We forgot to include "iostream"
    // on the top of the file, and as a result the compiler is not able to locate any function of that sort.
    int double{0}; // The error message is: Expected primary-expression before "int". Type names like "int" and "double" are
   // reserved words, and as thus cannot be assigned as variable names
    std::cout << test("a"); // The error message is: invalid conversion from const char* to int. Since C++ is a statically typed language,
   // we cannot pass as parameter a string when it is supposed to be an integer.
}


// Exercise two

void uniq() {
    int num{0};
    std::string old_line;
    for (std::string line; std::getline(std::cin, line);) {    //I chose the for loop over thw while one because the strng variable "line" goes out
    //of scope once the loop ends
        if (old_line == line) {
            num += 1;
        }
        else {
            num += 1;
            if (!old_line.empty()) std::cout << num << " " << old_line;
            num = 0;
            old_line = line;
        }
    }
}


// Exercise three

int get_int() {
    int line{};
    while (!(std::cin >> line)) { //the other option cannot be used because will return as soon as a wrong input is fed
        std::cin.clear();
        std::cin.ignore();
    }
    return line;
}


double get_double() {
    double line{};
    while (!(std::cin >> line)) {
        std::cin.clear();
        std::cin.ignore();
    }
    return line - (int)line;
}


// Exercise four

void units_of_measure(double number, std::string unit) {
    if (unit == "inch") std::cout << number / 40.0 << " " << "m";
    if (unit == "C") std::cout << number + 273.15 << " " << "K";
    if (unit == "ounce") std::cout << number * 29.16 << " " << "g";
}


// Exercise five

std::string text_formatter(int num) {
    std::string result;
    std::string line;
    std::cin >> line;
    int len = line.length();
    if (len <= num) return line;
    int i{0};
    while (i < num) {
        result += line[i];
        ++i;
    }
    while (line[i] != ' ') {
        result += line[i];
        if (i == len - 1) return result;
        else ++i;
    }
    return result;
}


// Main function

int main() {
    return 0;
}
