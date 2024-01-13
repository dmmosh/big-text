#include <boost/archive/text_oarchive.hpp> //serialization
#include <boost/archive/text_iarchive.hpp> 
#include <fstream>
#include <string>
#include <iostream>
using namespace boost::archive;

void save()
{
  std::ofstream file{"archive.txt"};
  text_oarchive oa{file};
  int i = 1;
  oa << i;
}

void load()
{
  std::ifstream file{"archive.txt"};
  text_iarchive ia{file};
  int i = 0;
  ia >> i;
  std::cout << i << '\n';
}

int main()
{
  save();
  load();
}
