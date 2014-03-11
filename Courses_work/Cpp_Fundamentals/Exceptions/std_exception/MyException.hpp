#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <exception>

class MyException : public std::exception {
  public:
    MyException(const std::string& message);
    virtual const char* what() const throw();
    ~MyException() throw() {}

  
  private:
    std::string message;
};

#endif
