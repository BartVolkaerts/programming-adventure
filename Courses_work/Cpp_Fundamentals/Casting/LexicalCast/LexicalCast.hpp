#ifndef LEXICALCAST_HPP
#define LEXICALCAST_HPP

#include <sstream>
using namespace std;

namespace tass {
template <class T, class S> T lexical_cast(S input) {
  stringstream s;
  s << input;
  T temp;
  s >> temp;
  return temp;
}
}

#endif
