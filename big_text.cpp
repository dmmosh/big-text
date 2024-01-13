#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <string.h>
#define N '\n'

/*
LE BIG TEXT 
(in terminal)

TODO: add support for more big text
(cd coding/big_text/; git-cl big_text.cpp -o big_text && ./big_text --help)

*/


//converts to BIG text
//string as value because it might be modified
std::string big_text(const std::string& input){

    //TOP BIG LETTERS (match the bottom)
    const std::vector<std::string> top_big = {
        "▄▀█", "█▄▄", "█▀▀", "█▀▄", "█▀▀", "█▀▀", "█▀▀", "█ █", "█", "  █", "█▄▀", "█  ", 
        "█▀▄▀█", "█▄ █", "█▀█", "█▀█", "█▀█", "█▀█", "█▀", "▀█▀", "█ █", "█ █", "█ █ █", 
        "▀▄▀", "█▄█", "▀█", 
        
        "█▀█", "▄█", "▀█", "▀▀█", "█ █", "█▀", "█▄▄", "▀▀█", "▄▀▀▄", "█▀█"
    };

    //BOTTOM BIG LETTERS (match the top)
    //a - z and 0 -9 
    const std::vector<std::string> bottom_big = {
        "█▀█", "█▄█", "█▄▄", "█▄▀", "██▄", "█▀ ", "█▄█", "█▀█", "█", "█▄█", "█ █", "█▄▄", 
        "█ ▀ █", "█ ▀█", "█▄█", "█▀▀", "▀▀█", "█▀▄", "▄█", " █ ", "█▄█", "▀▄▀", "▀▄▀▄▀", 
        "█ █", " █ ", "█▄", 
        
        "█▄█", " █", "█▄", "▄▄█", "▀▀█", "▄█", "█▄█", "  █", "▀██▀", "▀▀█"
    };

    //outputs
    std::string top_line;
    std::string top; 
    std::string bottom;
    std::string bottom_line;


    for(const char c: input){
        switch(tolower(c)){
            case 'a' ... 'z': 
                //appends the big version strings of each
                top += top_big[(int)tolower(c)-97];
                bottom += bottom_big[(int)tolower(c)-97];
                break;
            
            case '0' ... '9':
                //decimal - 48 + 26
                top+= top_big[(int)c-22];
                bottom+= bottom_big[(int)c-22];
                break;

            //special characters
            case '.':  top += ' '; bottom += "▄"; break;
            case '\'': top += "▀"; bottom += ' '; break;
            case '-': top += "▄▄"; bottom += "  "; break;
            case ' ':  top += ' '; bottom += ' '; break;
            case '!': top += "█"; bottom += "▄"; break;
            case '?': top += "▀█"; bottom += " ▄"; break;
            default: continue; //skips any and all other characters
        }
        //adds separator
        top += ' ';
        bottom += ' ';
    }

    
    //adds the lines
    for(int i=0; i<top.size()/2; ++i){
        top_line += "▀";
        bottom_line += "▄";
    }

    //returns the fat string
    return top_line + N + top + N + bottom + N + bottom_line + N;

};


int main(int argc, char** argv){
    
    std::vector<std::string> out;


    for(int i=1; i<argc; i++){ //iterates over the argument list
        if(!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            std::system(("echo -e \"" + big_text("BIG ASS TEXT") + 
            "by Dmytro Moshkovskyi\n" +
            "function from Inficonnect4 made for a terminal executable\n" +
            "written in c++\n\"").c_str());
            return 0;
        }

        //if first element or has newline 
        //makes a new element and iterates to it
        if (i ==1 || !strcmp(argv[i], "\n")) {
            out.push_back("");
        }

        out.back() += argv[i];
        out.back() += " ";
        
    }
    
    
    // ARGV LIST IS THE PARAMTERS TO THE EXECUTABLE!!
    //std::cout << argv[1] << N;

    //std::system(("echo -e \"" + text_output + "\"").c_str());
}