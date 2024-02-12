#include "./header.h"


const std::vector<std::string> btxt::top_big = {
    "▄▀█", "█▄▄", "█▀▀", "█▀▄", "█▀▀", "█▀▀", "█▀▀", "█ █", "█", "  █", "█▄▀", "█  ", 
    "█▀▄▀█", "█▄ █", "█▀█", "█▀█", "█▀█", "█▀█", "█▀", "▀█▀", "█ █", "█ █", "█ █ █", 
    "▀▄▀", "█▄█", "▀█", 
    
    "█▀█", "▄█", "▀█", "▀▀█", "█ █", "█▀", "█▄▄", "▀▀█", "▄▀▀▄", "█▀█"
};

const std::vector<std::string> btxt::bottom_big = {
    "█▀█", "█▄█", "█▄▄", "█▄▀", "██▄", "█▀ ", "█▄█", "█▀█", "█", "█▄█", "█ █", "█▄▄", 
    "█ ▀ █", "█ ▀█", "█▄█", "█▀▀", "▀▀█", "█▀▄", "▄█", " █ ", "█▄█", "▀▄▀", "▀▄▀▄▀", 
    "█ █", " █ ", "█▄", 
        
    "█▄█", " █", "█▄", "▄▄█", "▀▀█", "▄█", "█▄█", "  █", "▀██▀", "▀▀█"
};

//converts to BIG text
//string as value because it might be modified
// constructor
btxt::btxt(const std::string& input, const bool& have_lines): 

// member initialization list
top_line(""),
top(""),
bottom(""),
bottom_line(""),
char_str(0)
{
    
    //output struct

    if(!input.length()){
        top = "\n"; //top is newline
        return;
    }


    for(const char c: input){
        bool skip = false;
        switch(tolower(c)){
            //letters
            case 'a' ... 'z': 
                //appends the big version strings of each
                top += top_big[(int)tolower(c)-97];
                bottom += bottom_big[(int)tolower(c)-97];
                switch(tolower(c)){
                    case 'i': char_str++; break;
                    case 'm': case 'w': char_str+=5; break;
                    case 's': case 'z': char_str+=2; break;
                    default: char_str+=3;  
                }
                break;
            //numbers
            case '0' ... '9':
                //decimal - 48 + 26
                top+= top_big[(int)c-22];
                bottom+= bottom_big[(int)c-22];
                switch(tolower(c)){
                    case '1': case '2': case '5': char_str+=2; break;
                    case '8': char_str +=4; break;
                    default: char_str +=3;
                }
                break;

            //special characters
            case '.':  top += ' '; bottom += "▄"; char_str++; break;
            case '\'': top += "▀"; bottom += ' '; char_str++; break;
            case '-': top += "▄▄"; bottom += "  "; char_str+=2; break;
            case ' ':  top += ' '; bottom += ' '; char_str++; break;
            case '!': top += "█"; bottom += "▄"; char_str++; break;
            case '?': top += "▀█"; bottom += " ▄"; char_str+=2; break;
            default: skip=true; //skips any and all other characters
        }
        if(skip){
            continue;
        }

        //adds separator
        char_str++; //3 chars + space 
        top += ' ';
        bottom += ' ';
    }
    


    top.resize(top.size() - 1);
    bottom.resize(bottom.size() - 1);

    //adds the lines
    if(have_lines){
        for(size_t i=0; i<char_str-1; i++){
            top_line += "▀";
            bottom_line += "▄";
        }
        top_line += N;
        bottom_line += N;
    }

    //std::cout << char_str << N << char_ctr << N << t_cols << N;
    //returns the fat string
};

//converts variables to a string
std::string btxt::to_string(){
    return top_line + top + N + bottom+ N + bottom_line;
}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
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

//prints the help page erf
void help(const std::string& path) {
    btxt text1("massive text", 1);
    btxt text2("...ginormous even", 0);

    sys(std::string(N + "fdsjhfdk"));
    std::ifstream docs(std::string(path) + "commands.txt");
    std::string line;
    while (getline(docs, line)){
        std::system(("echo -e \"" + line + "\"").c_str());
    }
}

template<typename T>
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

//system calls but string as input
void sys(const std::string& input){
    std::system(input.c_str());
}