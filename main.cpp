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
    

    std::string out; //output words, not big yet
    bool line = 1; //whether to have a line or not, default 1
    int repeat = 1; //whether to repeat or notfdsf

    for(int i=1; i<argc; i++){ //iterates over the argument list
        std::string arg_input = argv[i]; //converts to string

        // -h, --help
        if(arg_input == "--help" || arg_input == "-h") {
            help(path);
            return 0;
        // -n, --newline
        } else if(arg_input == "--newline" || arg_input == "-n") {
            if(out.length() != 0){
                out.resize(out.size() -1);
            };
            out += '\n';
        // -nl, --no-lines
        } else if(arg_input == "--no-lines" || arg_input == "-nl") {
            line = 0; //removes lines
        // -x=
        } else if(arg_input.substr(0,3) == "-x=") {
            if(!is_int(arg_input, 3)) {
                sys("ERROR: can't multiply, not a number specified");
                return 0;
            }
            repeat = std::stoi(arg_input.substr(3)); //sets to the repeat value
        // --times=
        } else if (arg_input.substr(0,8) == "--times=") {
            if(!is_int(arg_input, 9)) {
                sys("ERROR: can't multiply, not a number specified");
                return 0;
            }
            repeat = std::stoi(arg_input.substr(9)); //sets to the repeat value
        } else {

        //if first element or has newline 
        //makes a new element and iterates to it fdg
    
        
        }
    }

    //remove space from last element
    if(out.length() != 0){
        out.resize(out.size() -1);
    }

    static int t_cols = std::stoi(exec("stty size | awk '{print $2}'"));


    while(repeat){
        std::string final_out; //big text output for each parameter
        int char_ctr = 0; //counter of characters 

        for(std::string out_str: out)
        {
            btxt out(out_str, line);

            //if not newline character, add to char counter. otherwise reset
            char_ctr = (out.char_str >= 0) ? char_ctr + out.char_str : 0;


            //if total chars above terminal's char counter, add a newline character
            //std::cout << out.char_str -1 << N;

            
            final_out += out.to_str();
            final_out += "CHAR COUNTER: ";
            final_out += std::to_string(char_ctr);
            final_out += N;
        }

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

    // arg_input LIST IS THE PARAMTERS TO THE EXECUTABLE!!
    //std::cout << arg_input[1] << N;
    //fdsagh
    //std::system(("echo -e \"" + text_output + "\"").c_str());
}
