#include <boost/archive/text_oarchive.hpp> //serialization
#include <boost/archive/text_iarchive.hpp> 
#include <fstream>
#include <string>


int main() {
    std::ifstream txtFile("etc/commands.txt");
    std::ofstream file{"etc/commands"};
    boost::archive::text_oarchive oa(file);

    std::string stream;

    while(getline(txtFile, stream)) {
        oa << "fdjsl" << '\n'; 
    }
}