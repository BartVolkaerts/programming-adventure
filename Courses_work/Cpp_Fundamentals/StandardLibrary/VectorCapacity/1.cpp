#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;

int main(int argc, char **argv) {
  int i;
  vector<int> numbers;
  numbers.reserve(argc-1);
  
  for(i=1; i < argc; i++) {
    numbers.push_back(boost::lexical_cast<int>(argv[i]));
  }

  cout << "Capacity: " << numbers.capacity() << endl;

  numbers.push_back(boost::lexical_cast<int>(10));
  cout << "Capacity: " << numbers.capacity() << endl;
}
