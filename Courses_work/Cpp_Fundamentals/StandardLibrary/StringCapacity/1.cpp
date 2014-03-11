#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  string s("Foo");
  cout << "Data: " << s << endl << "Size: " << s.length() << endl << "Capacity: " << s.capacity() << endl;

  s = "Bart is cool";
  cout << "Data: " << s << endl << "Size: " << s.length() << endl << "Capacity: " << s.capacity() << endl;

  s = "Bart is cool,maar C++ is cooler";
  cout << "Data: " << s << endl << "Size: " << s.length() << endl << "Capacity: " << s.capacity() << endl;
}
