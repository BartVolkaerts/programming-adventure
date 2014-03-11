#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;

int main(int argc, char **argv) {
  int i;
  vector<int> numbers;
  numbers.reserve(argc-1);
  
  for(i=1; i < argc; i++) {
    try {
      numbers.push_back(boost::lexical_cast<int>(argv[i]));
    }
    catch (...) {
      cerr << "Foutje" << endl;
    }
  }

  vector<int>::reverse_iterator it;
  for(it = numbers.rbegin(); it != numbers.rend(); it++) {
    cout << *it << endl;
  }
}
