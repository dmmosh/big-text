#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <string.h>
#define N '\n'

/*
LE BIG TEXT 
(in terminal)
fd
TODO: add support for more big text
(cd coding/big-text/; git-cl big_text.cpp -o big_text && ./big_text --help)

*/


// if windows 32/64 bit , run a command to allow ufc 8 encoding
// lazy fix for windows
#if _WIN32
    std::system("chcp 65001");
#endif


//converts to BIG text
//string as value because it might be modified
std::string big_text(const std::string& input, const bool& have_lines){

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
    return 
    ((have_lines) ? top_line + N : "") + 
        top + N + bottom + N + 
    ((have_lines) ? bottom_line + N : "");

};

// if string is an int
bool is_int(const char* string, int start_i=0) {
    while(string[start_i] != '\0'){
        if(!isdigit(string[start_i])) {
            return false;
        }
        start_i++;
    }
    return true;
}

int main(int argc, char** argv){
    
    std::vector<std::string> out = {""};
    bool line = 1; //whether to have a line or not
    int repeat = 1; //whether to repeat or not

    for(int i=1; i<argc; i++){ //iterates over the argument list

        // -h, --help
        if(!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            std::system(("echo -e \"OVERVIEW:\n" + 
            big_text("BIG ASS TEXT", 1) + 
            "by Dmytro Moshkovskyi\n" +
            "function from Inficonnect4\n" +
            "made for a terminal executable\n" +
            "written in c++\n\"").c_str());
            return 0;
        // -n, --newline
        } else if(!strcmp(argv[i], "--newline") || !strcmp(argv[i], "-n")) {
            out.back().resize(out.back().size() -1); //removes the space
            out.push_back(""); //pushes a new element
            continue; 
        
        // -nl, --no-lines
        } else if(!strcmp(argv[i], "--no-lines") || !strcmp(argv[i], "-nl")) {
            line = 0; //removes lines
            continue;
        
        // -x=
        } else if(!strncmp(argv[i], "-x=", 3)) {
            if(!is_int(argv[i], 3)) {
                std::system("echo -e \"ERROR: can't multiply, not a number specified\"");
                return 0;
            }
            repeat = std::stoi(std::string(argv[i]).substr(3)); //sets to the repeat value
            continue;

        // --times=
        } else if (!strncmp(argv[i], "--times=", 8)) {
            if(!is_int(argv[i], 8)) {
                std::system("echo -e \"ERROR: can't multiply, not a number specified\"");
                return 0;
            }
            repeat = std::stoi(std::string(argv[i]).substr(8)); //sets to the repeat value
            continue;
        
        }

        //if first element or has newline 
        //makes a new element and iterates to it
        

        out.back() += argv[i];
        out.back() += " ";
        
    }

    //remove space from last element
    if(out.back().length()){
        out.back().resize(out.back().size() -1);
    }


    do{
    for(std::string& out_str : out) {
        out_str = big_text(out_str, line);
        std::system(("echo -e \"" + out_str + "\"").c_str());
    }
    repeat--;
    } while(repeat) //clears the repeat value

    // ARGV LIST IS THE PARAMTERS TO THE EXECUTABLE!!
    //std::cout << argv[1] << N;

    //std::system(("echo -e \"" + text_output + "\"").c_str());
}