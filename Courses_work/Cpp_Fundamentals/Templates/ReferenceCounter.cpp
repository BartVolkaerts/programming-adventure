#include "ReferenceCounter.hpp"
#include <iostream>
using namespace std;


ReferenceCounter::ReferenceCounter() : 
  counter(new unsigned int)
{
  cout << "RefCtr default CopyCtor : Counter set to 1" << endl;
  *counter =1;
}

ReferenceCounter::ReferenceCounter(const ReferenceCounter& r) :
  counter(r.counter)
{
  (*counter)++;  
  cout << "RefCtr CopyCtor Counter inc to " << (*counter) << endl;
}

ReferenceCounter::~ReferenceCounter()
{
  cout << "RefCtr destructor called" << endl;
  (*counter)--;
  
  cout << "Counter dec to " << (*counter) << endl;
  if ( 0 == *counter)
  { 
    cout << "Counter deleted" << endl;
    delete counter;
  }
}

ReferenceCounter& ReferenceCounter::operator=(const ReferenceCounter& r)
{
  cout << "RefCtr = used. Counter = " << *counter << endl; 
  if (this != &r)
  {
    (*counter)--;
    if ( 0 == *counter)
      delete counter;
    counter = r.counter;
    (*counter)++;
     cout << "this != &r :  Counter inc to " << *counter << endl; 
  }
  cout << this << endl;
  cout << &r << endl;
  return *this;
}

