#include "./header.h"

/*
LE BIG TEXT 
(in terminal)
ffdsjld
TODO: add support for more big text
(cd coding/big-text/; git-cl -o btxt main.cpp utils.cpp; ./btxt hiii -x=10);
dsj
*/




int main(int argc, char** argv){

    
    //gets the path of executable 
    static std::string path = argv[0];

    for(int i=path.length(); i>=0; i--){
        if(path[i] == '/'){
            path.resize(i+1);
            break;
        }       
    };

    //if no arguments are provided, just print the help page
    if(argc == 1) {
        help(path);
        return 0;
    }
    

    std::vector<std::string> out = {""}; //output words, not big yet
    bool line = 1; //whether to have a line or not, default 1
    int repeat = 1; //whether to repeat or notfdsf

    for(int i=1; i<argc; i++){ //iterates over the argument list

        // -h, --help
        if(!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            help(path);
            return 0;
        // -n, --newline
        } else if(!strcmp(argv[i], "--newline") || !strcmp(argv[i], "-n")) {
            if(out.back().length() != 0){
                out.back().resize(out.back().size() -1);
            };
            out.push_back(""); //pushes a new element
        // -nl, --no-lines
        } else if(!strcmp(argv[i], "--no-lines") || !strcmp(argv[i], "-nl")) {
            line = 0; //removes lines
        // -x=
        } else if(!strncmp(argv[i], "-x=", 3)) {
            if(!is_int(argv[i], 3)) {
                sys("ERROR: can't multiply, not a number specified");
                return 0;
            }
            repeat = std::stoi(std::string(argv[i]).substr(3)); //sets to the repeat value
        // --times=
        } else if (!strncmp(argv[i], "--repeat=", 9)) {
            if(!is_int(argv[i], 9)) {
                sys("ERROR: can't multiply, not a number specified");
                return 0;
            }
            repeat = std::stoi(std::string(argv[i]).substr(9)); //sets to the repeat value
        } else {

        //if first element or has newline 
        //makes a new element and iterates to it fdg
    
        out.back() += argv[i];
        out.back() += " ";
        }
    }

    
    //remove space from last element
    if(out.back().length() != 0){
        out.back().resize(out.back().size() -1);
    }

    static int t_cols = std::stoi(exec("stty size | awk '{print $2}'"));

    std::string final_out; //big text output for each parameter
    int char_ctr = 0; //counter of characters 

    for(std::string out_str: out)
    {
        btxt out(out_str, line);

        char_ctr += out.char_str; //adds string's size to total char counter

        //if total chars above terminal's char counter, add a newline character
        std::cout << out.char_str << N;
        if (char_ctr > t_cols)
        {
            char_ctr = 0;
        }
        final_out += out.to_str();
    }

    while(repeat){
        sys(final_out);
        repeat--;
    }
    

    /*
    //copies the wanted amount of times
    std::vector<std::string> final_out;
    while (repeat){
        final_out.insert(final_out.end(), out.begin(), out.end());
        repeat--;
    };

    //prints the big textgfdfg

    //prints the big text (multiplied times)
    for(std::string& out_str : final_out) {
        btxt out(out_str, line);


        char_ctr += out.char_str;
        //if character counter is bigger than the number of columns
        std::cout << char_ctr << N;
        sys(out.to_str());
    }
    */

    //terminal column char size

    // ARGV LIST IS THE PARAMTERS TO THE EXECUTABLE!!
    //std::cout << argv[1] << N;
    //fdsagh
    //std::system(("echo -e \"" + text_output + "\"").c_str());
}
