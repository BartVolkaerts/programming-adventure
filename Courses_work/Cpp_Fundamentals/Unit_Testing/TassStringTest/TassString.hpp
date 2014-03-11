#ifndef TASSSTRING_H
#define TASSSTRING_H

#include <cstring>
#include <iostream>
using namespace std;

class TassString {
  public:
    TassString();
    ~TassString();
    TassString(const TassString& str);
    TassString(const TassString& str, size_t pos, size_t len);
    TassString(const char *s);
    TassString(const char *s, size_t n);
    TassString(size_t n, char c);

    TassString& operator=(const TassString& str);
    bool operator==(TassString& str) const;
    bool operator!=(TassString& str) const;
    TassString operator+(TassString& str) const;
    int length() const;
    char *print() const;

  private:
    char *data;
    size_t size;
};

#endif 
