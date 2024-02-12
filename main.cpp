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

    //if no arguments are provided, just print the help page
    if(argc == 1) {
        help(argv[0]);
        return 0;
    }
    

    std::string out; //output words, not big yet
    bool line = 1; //whether to have a line or not, default 1
    int repeat = 1; //whether to repeat or notfdsf

    for(int i=1; i<argc; i++){ //iterates over the argument list
        std::string arg_input = argv[i]; //converts to string

        // -h, --help
        if(arg_input == "--help" || arg_input == "-h") {
            help(argv[0]);
            return 0;
        // -n, --newline
        } else if(arg_input == "--newline" || arg_input == "-n") {
            //remove space at the end 
            if(out.length() != 0){
                out.resize(out.size() -1);
            };
            out += '\n'; //add newline
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

        //adds to the output string
        out += arg_input + " ";

        }
    }

    //remove space from last element
    if(out.length() != 0){
        out.resize(out.size() -1);
    }

    static int t_cols = std::stoi(exec("stty size | awk '{print $2}'")); //terminal size



    std::vector<btxt> big_out;
    //iterate over characters in the output string
    int start_i = 0;
    int end_i = 0;
    for(const char& c: out){
        switch (c)
        {
        case '\n':
            big_out.push_back(btxt(line));
        case ' ':

        break;
        }
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
