#include "TassString.hpp"

TassString::TassString() : data(), size() {
}

TassString::~TassString() {
  if (data != NULL)
    delete(data);
}

TassString::TassString(const TassString& str) 
  : data(new char[str.size]), size(str.size) {
  strcpy(data, str.data);
}

TassString::TassString(const TassString& str, size_t pos, size_t len) 
  : data(new char[len]), size(len) {
  strncpy(data, &str.data[pos], len);
}

TassString::TassString(const char *s) 
  : data(),size(strlen(s)) {
  data = new char[size];
  strcpy(data, s);
}

TassString::TassString(const char *s, size_t n)
  : data(new char[n]), size(n) {
  strncpy(data, s, size);
}

TassString::TassString(size_t n, char c) 
  : data(), size(n) {
  data = new char[size];
  memset(data, c, size);
  data[size] = '\0';
}

int TassString::length() const {
  return size;
}

char* TassString::print() const {
  return data;
}

bool TassString::operator == (TassString& str) const {
  int i;
  if (this->size != str.size)
    return false;
  
  i = strcmp(this->data, str.data);
  if (i == 1 || i == -1)
    return false;
  else
    return true;
}

bool TassString::operator != (TassString& str) const {
  int i; 
  if (this->size != str.size)
    return true;

  i = strcmp(this->data, str.data);
  if (i == 1 || i == -1)
    return true;
  else
    return false;
}

TassString& TassString::operator = (const TassString &str) {
  if (this != &str) {
    delete (this->data);
    this->data = new char[str.size];
    strcpy(this->data, str.data);
    this->size = str.size;
  }
  return *this;
}

TassString TassString::operator + (TassString &str) const {
  size_t newsize = this->size + str.size;
  char newdata[newsize];
  strcpy(newdata,this->data);
  strcpy(&newdata[this->size],str.data);
  TassString temp(newdata);
  return temp;
}
