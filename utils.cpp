#include "./header.h"


//converts to BIG text
//string as value because it might be modified
std::string big_text(const std::string& input, const bool& have_lines){
    if(!input.length()){
        return "\n";
    }

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
    do {
        if(!isdigit(string[start_i])) {
            return false;
        }
        start_i++;
    } while(string[start_i] != '\0');
    return true;
}

//prints the help page
void help(const std::string& path) {
    std::system(("echo -e \"OVERVIEW:\n" + 
    big_text("MASSIVE TEXT", 1) + "\"").c_str());
    std::ifstream docs(std::string(path) + "commands.txt");
    std::string line;
    while (getline(docs, line)){
        std::system(("echo -e \"" + line + "\"").c_str());
    }
}