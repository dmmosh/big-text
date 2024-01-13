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
        "\u2584\u2580\u2588", "\u2588\u2584\u2584", "\u2588\u2580\u2580", "\u2588\u2580\u2584", "\u2588\u2580\u2580", "\u2588\u2580\u2580", "\u2588\u2580\u2580", "\u2588 \u2588", "\u2588", "  \u2588", "\u2588\u2584\u2580", "\u2588  ", 
        "\u2588\u2580\u2584\u2580\u2588", "\u2588\u2584 \u2588", "\u2588\u2580\u2588", "\u2588\u2580\u2588", "\u2588\u2580\u2588", "\u2588\u2580\u2588", "\u2588\u2580", "\u2580\u2588\u2580", "\u2588 \u2588", "\u2588 \u2588", "\u2588 \u2588 \u2588", 
        "\u2580\u2584\u2580", "\u2588\u2584\u2588", "\u2580\u2588", 
        
        "\u2588\u2580\u2588", "\u2584\u2588", "\u2580\u2588", "\u2580\u2580\u2588", "\u2588 \u2588", "\u2588\u2580", "\u2588\u2584\u2584", "\u2580\u2580\u2588", "\u2584\u2580\u2580\u2584", "\u2588\u2580\u2588"
    };

    //BOTTOM BIG LETTERS (match the top)
    //a - z and 0 -9 
    const std::vector<std::string> bottom_big = {
        "\u2588\u2580\u2588", "\u2588\u2584\u2588", "\u2588\u2584\u2584", "\u2588\u2584\u2580", "\u2588\u2588\u2584", "\u2588\u2580 ", "\u2588\u2584\u2588", "\u2588\u2580\u2588", "\u2588", "\u2588\u2584\u2588", "\u2588 \u2588", "\u2588\u2584\u2584", 
        "\u2588 \u2580 \u2588", "\u2588 \u2580\u2588", "\u2588\u2584\u2588", "\u2588\u2580\u2580", "\u2580\u2580\u2588", "\u2588\u2580\u2584", "\u2584\u2588", " \u2588 ", "\u2588\u2584\u2588", "\u2580\u2584\u2580", "\u2580\u2584\u2580\u2584\u2580", 
        "\u2588 \u2588", " \u2588 ", "\u2588\u2584", 
        
        "\u2588\u2584\u2588", " \u2588", "\u2588\u2584", "\u2584\u2584\u2588", "\u2580\u2580\u2588", "\u2584\u2588", "\u2588\u2584\u2588", "  \u2588", "\u2580\u2588\u2588\u2580", "\u2580\u2580\u2588"
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
            case '.':  top += ' '; bottom += "\u2584"; break;
            case '\'': top += "\u2580"; bottom += ' '; break;
            case '-': top += "\u2584\u2584"; bottom += "  "; break;
            case ' ':  top += ' '; bottom += ' '; break;
            case '!': top += "\u2588"; bottom += "\u2584"; break;
            case '?': top += "\u2580\u2588"; bottom += " \u2584"; break;
            default: continue; //skips any and all other characters
        }
        //adds separator
        top += ' ';
        bottom += ' ';
    }

    
    //adds the lines
    for(int i=0; i<top.size()/2; ++i){
        top_line += "\u2580";
        bottom_line += "\u2584";
    }

    //returns the fat string
    return top_line + N + top + N + bottom + N + bottom_line + N;

};


int main(int argc, char** argv){
    
    std::string out; //output
    for(int i=1; i<argc; i++){ //iterates over the argument list
        if(!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            std::system(("echo -e \"" + big_text("BIG ASS TEXT") + 
            "by Dmytro Moshkovskyi\n" +
            "function from Inficonnect4 made for a terminal executable\n" +
            "written in c++\n\"").c_str());
            continue;
        }
        out += argv[i];
        out += " ";
        
    }
    out.resize(out.size()-1); //removes last space
    
    
    int iterate_time = (argv[argc]) ? std::atoi(argv[2]) : 0;
    

    // ARGV LIST IS THE PARAMTERS TO THE EXECUTABLE!!
    //std::cout << argv[1] << N;
    int i =0;

    do{
    std::system(("echo -e \"" + big_text(out) + "\"").c_str());
    i++;
    } while (i<iterate_time);
}