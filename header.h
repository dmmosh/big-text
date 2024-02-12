#pragma once 
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <filesystem>
#include <array>
#define N '\n'



class btxt{

    public:
    static const std::vector<std::string> top_big; //top characters
    static const std::vector<std::string> bottom_big; //bottom characters
    std::string top_line; //top line
    std::string top; //top text
    std::string bottom; //bottom text
    std::string bottom_line; //bottom line
    
    int char_str; //the character counter (utf 8 characters are weird in c)
    bool have_lines; //if have lines or not

    btxt(const bool& have_lines); //constructor 1
    btxt(const std::string& input, const bool& have_lines); //constructor 2
    btxt(const char& input, const bool& have_lines); //constructor 3
    btxt& operator+(const char& c);
    btxt& operator+=(const char& c);  //overloads += operator
    
    std::string to_str(); //converts big text to string
};



//converts to BIG text
//string as value because it might be modified

//executes command and returns the output
std::string exec(const char* cmd);


// if string is an int
bool is_int(const std::string& input, const int& start_i);


template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& input) {
    for(T out_var: input){
        out << out_var;
    }
    return out << N; 
};

void help(const char* path); //help page

void test(); //test the text

std::string exec(const char* cmd); //executes the command

void sys_btxt(const std::string& out, const bool& line, int repeat);

void sys(const std::string& input);
