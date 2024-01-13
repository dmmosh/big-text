#include <boost/archive/text_oarchive.hpp> //serialization
#include <boost/archive/text_iarchive.hpp> 
#include <fstream>
#include <string>


int main() {
    std::ifstream txtFile("etc/commands.txt");
    std::ofstream ofc("etc/commands");

    std::string stream;
    
    boost::archive::text_oarchive oa(ofc);

    while(getline(txtFile, stream)) {
        oa << stream << '\n'; 
    }
}