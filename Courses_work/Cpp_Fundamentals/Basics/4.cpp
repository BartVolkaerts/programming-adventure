#include <iostream>
#define CURRENTYEAR 2014

using namespace std;

int main(int argc, char **argv)
{
  int year;
  cout << "What is your age?" << endl;
  cin >> year;
  cout << "You were born in " << (CURRENTYEAR-year) << endl;
}

