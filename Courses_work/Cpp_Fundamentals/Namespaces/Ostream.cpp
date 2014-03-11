#include "Ostream.hpp" 

using namespace tass;
ostream tass::cout;
ostream::endline tass::endl; 

ostream& ostream::operator<<(const char *p) {
  if (newLine) {
    std::time_t now = system_clock::to_time_t(system_clock::now());
    std::tm* local = localtime(&now);
    std::cout << local->tm_hour << ":" << local->tm_min << "\t";
    newLine = 0;
  }
  std::cout << p;
  return *this;
}

ostream& ostream::operator<<(ostream::endline endl) {
  std::cout << std::endl;
  newLine = 1;
  return *this;
}
