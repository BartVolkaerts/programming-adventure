#include "MyException.hpp"

MyException::MyException(const std::string& msg)
  : message(msg) {}

const char* MyException::what() const throw() {
  return message.c_str();
}
