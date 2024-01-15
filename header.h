#pragma once 
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <filesystem>
#define N '\n'

//converts to BIG text
//string as value because it might be modified
std::string big_text(const std::string& input, const bool& have_lines);

// if string is an int
bool is_int(const char* string, int start_i);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& input) {
    for(T out_var: input){
        out << out_var;
    }
    return out << N;
}

void help(const std::string& path);