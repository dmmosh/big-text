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
    std::vector<std::string> top_big;
    std::vector<std::string> bottom_big;
    std::string top_line; //top line
    std::string top; //top text
    std::string bottom; //bottom text
    std::string bottom_line; //bottom line
    
    int char_str; //the character counter (utf 8 characters are weird in c)

    btxt(const std::string& input, const bool& have_lines);
    std::string to_string();
};

//converts to BIG text
//string as value because it might be modified

//executes command and returns the output
std::string exec(const char* cmd);


// if string is an int
bool is_int(const char* string, int start_i);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& input) {
    for(T out_var: input){
        out << out_var;
    }
    return out << N; 
}

void help(const std::string& path); //help page

std::string exec(const char* cmd); //executes the command

void sys(const std::string& input);