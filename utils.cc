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
char_str(0),
have_lines(have_lines) 
{
    //operator overloading and stuff
    for(const char& c: input){
        *this += c;
    }
};


//constructor 3
btxt::btxt(const char& input, const bool& have_lines):

// member initialization list
top_line(""),
top(""),
bottom(""),
bottom_line(""),
char_str(0),
have_lines(have_lines) 
{

    //bruh
    *this += input;
};



//overloads += operator
btxt& btxt::operator+=(const char& c){


    switch(tolower(c)){
        //letters
        case 'a' ... 'z': 
            //appends the big version strings of each
            this->top += this->top_big[(int)tolower(c)-97];
            this->bottom += this->bottom_big[(int)tolower(c)-97];
            switch(tolower(c)){
                case 'i': this->char_str++; break;
                case 'm': case 'w': this->char_str+=5; break;
                case 's': case 'z': this->char_str+=2; break;
                case 'n': this->char_str+=4; break;
                default: this->char_str+=3;  
            }
            break;
        //numbers
        case '0' ... '9':
            //decimal - 48 + 26
            this->top+= this->top_big[(int)c-22];
            this->bottom+= this->bottom_big[(int)c-22];
            switch(tolower(c)){
                case '1': case '2': case '5': this->char_str+=2; break;
                case '8': this->char_str +=4; break;
                default: this->char_str +=3;
            }
            break;
        //special characters
        case '.':  this->top += ' '; this->bottom += "▄"; this->char_str++; break;
        case ',': this->top += ' '; this->bottom += "█"; this->char_str++; break;
        case '\'': this->top += "▀"; this->bottom += ' '; this->char_str++; break;
        case '-': this->top += "▄▄"; this->bottom += "  "; this->char_str+=2; break;
        case ' ':  this->top += ' '; this->bottom += ' '; this->char_str++; break;
        case '!': this->top += "█"; this->bottom += "▄"; this->char_str++; break;
        case '?': this->top += "▀█"; this->bottom += " ▄"; this->char_str+=2; break;
        default: return *this; //skips any and all other characters
    }
    
    //adds separator
    this->char_str++; //3 chars + space 
    this->top += ' ';
    this->bottom += ' ';

    return *this;
};



//converts variables to a string
std::string btxt::to_str(){

    

    //if include lines, print them 
    if(this->have_lines && this->top_line.empty() && this->bottom_line.empty()){
        for (size_t i = 0; i < this->char_str-1; i++)
        {
            this->top_line += "▀";
            this->bottom_line += "▄";
        }
        this->top_line += "\n";
        this->bottom_line += "\n";
    }

    return 
    top_line +
    top.substr(0, top.size()-1) + N + 
    bottom.substr(0, bottom.size()-1) + N + 
    bottom_line;
}


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

    sys("OVERVIEW:" );
    sys("Big Terminal Text" );
    sys("By Dmytro Moshkovskyi" );
    sys("https://github.com/wettestsock/big-text" );
    sys("Function from Inficonnect4 made for a terminal executable" );
    sys("written in C++ ");
    sys("\nUSAGE: " );
    sys("    btxt [options] text ..." );
    sys("" );
    sys("\nOPTIONS:" );
    sys("    -h, --help          help page" );
    sys("    -n, --newline       prints following text in a newline" );
    sys("    -nl, --no-lines     removes the top and bottom lines, enabled by default" );
    sys("    -x=, --repeat=<value> repeats the text a given N times\n" );
    sys("    -t, --test          tests the text\n");
}

void test(){
    sys(btxt("the brown fox jumps over the lazy dog", 1).to_str());
    sys(btxt("0123456789", 1).to_str());
    sys(btxt(".,\\- !?", 1).to_str());
    sys(btxt("the brown fox jumps over the lazy dog", 0).to_str());
    sys(btxt("0123456789", 0).to_str());
    sys(btxt(".,\\- !?", 0).to_str());
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
}

void sys_btxt(const std::string& out, const bool& line, int repeat = 1){
    static int t_cols = std::stoi(exec("stty size | awk '{print $2}'")); //terminal size
    std::vector<btxt> big_out = {btxt(line)}; //vector of big text classes

    //iterate over characters in the output string
    for(const char& c: out){
        if(c == '\n' || big_out.back().char_str >= t_cols -4){
            //std::cout << t_cols-4 << N << big_out.back().char_str << N ; //debug 
            big_out.push_back(btxt(line));
        }

        big_out.back() += c;
        
    }

    while(repeat){
        for(btxt& text: big_out){
            sys(text.to_str());
        }
        repeat--;
    }
}


//system calls but string as input
void sys(const std::string& input){
        std::system(("echo -e \"" + input + "\"").c_str());
}
