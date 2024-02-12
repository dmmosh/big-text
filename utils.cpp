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
//constructor 1
btxt::btxt(const bool& have_lines): 

// member initialization list
top_line(""),
top(""),
bottom(""),
bottom_line(""),
char_str(0),
have_lines(have_lines) 
{};


//converts to BIG text
//string as value because it might be modified
// constructor 2 
// constructor overloading
btxt::btxt(const std::string& input, const bool& have_lines): 

// member initialization list
top_line(""),
top(""),
bottom(""),
bottom_line(""),
char_str(0)
{
    //operator overloading and stuff
    for(const char& c: input){
        *this += c;
    }
};

//overloads += operator
btxt& btxt::operator+=(const char& c){
    *this = *this + c;
    return *this;
};


//adds a character
//cant be newline, make sure that dont happen
btxt btxt::operator+(const char& c){

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
                case 'n': char_str+=4; break;
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
        //default: return *this; //skips any and all other characters
    }
    
    //adds separator
    char_str++; //3 chars + space 
    top += ' ';
    bottom += ' ';
    
    top.resize(top.size() - 1); //removes last spaces
    bottom.resize(bottom.size() - 1); //removes last spaces

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
    return *this;
};


//converts variables to a string
std::string btxt::to_str(){
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
bool is_int(const std::string& input, const int& start_i){
    for (const char& c: input.substr(start_i))
    {
        if(!isdigit(c)){
            return false;
        }
    }

    return true;
}

//prints the help page erf
void help(const char* path) {
    //gets the path of executable 
    static std::string path_input = path;

    //get the directory of the executable
    for(int i=path_input.length(); i>=0; i--){
        if(path_input[i] == '/'){
            path_input.resize(i+1);
            break;
        }       
    };

    sys(N + btxt("massive text", 1).to_str() + N + btxt("...ginormous even", 0).to_str());
    std::ifstream docs(std::string(path_input) + "commands.txt");
    std::string line;
    while (getline(docs, line)){
        sys(line);
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
        std::system(("echo -e \"" + input + "\"").c_str());
}