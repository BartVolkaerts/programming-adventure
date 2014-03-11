#ifndef OSTREAM_HPP
#define OSTREAM_HPP

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std::chrono;

namespace tass {
  class ostream {
    public:
      class endline {};
      ostream& operator << (const char*);
      ostream& operator << (endline);

    private:
      bool newLine = 1;
  };

  extern ostream cout;
  extern ostream::endline endl;
}

#endif
