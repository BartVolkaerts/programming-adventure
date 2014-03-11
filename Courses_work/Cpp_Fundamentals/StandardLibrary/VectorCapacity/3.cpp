#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <boost/lexical_cast.hpp>

using namespace std;

bool smaller_10 (int i)
{
  return (i<10);
}

int increment(int& i) {
  return ++i;
}

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

  cout << "----Reverse-----" << endl;
  vector<int>::const_reverse_iterator rit;
  for(rit = numbers.rbegin(); rit != numbers.rend(); rit++) {
    cout << *rit << endl;
  }

  cout << "----Min/Max-----" << endl;
  cout << "Max: " << *max_element(numbers.begin(),numbers.end()) << endl;
  cout << "Min: " << *min_element(numbers.begin(),numbers.end()) << endl;

  sort(numbers.begin(), numbers.end());
  cout << "----Sorted-----" << endl;
  vector<int>::const_iterator it;
  for(it = numbers.begin(); it != numbers.end(); it++) {
    cout << *it << endl;
  }

  cout << "----Removed<10-----" << endl;
  numbers.erase( remove_if(numbers.begin(),numbers.end(),smaller_10) , numbers.end());
  for(it = numbers.begin(); it != numbers.end(); it++) {
    cout << *it << endl;
  }

  cout << "----Increment transform-----" << endl;
  transform(numbers.begin(),numbers.end(),numbers.begin(),increment);
  for(it = numbers.begin(); it != numbers.end(); it++) {
    cout << *it << endl;
  }
  
  cout << "----Accumulate-----" << endl;
  cout << accumulate(numbers.begin(), numbers.end(), 0) << endl;

}
