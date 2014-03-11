#ifndef _SMART_POINTER_H_
#define _SMART_POINTER_H_

#include "ReferenceCounter.hpp"
using namespace std;

template <class T> class SmartPointer : protected ReferenceCounter{
  private:
    T* const pointee;
  public: 
    SmartPointer();
    SmartPointer(T* const p);
    SmartPointer(const SmartPointer<T>& p);
    SmartPointer<T> operator=(const SmartPointer<T>& p);
    virtual ~SmartPointer();
};

template<class T>
SmartPointer<T>::SmartPointer() :
  pointee() 
{
  cout << "Default smartCtor called at : " << this << endl;
}

template<class T>
SmartPointer<T>::SmartPointer(T* const p) :
  ReferenceCounter(), pointee(p) 
{
  cout << "SmartPtr Ctor by ptr called at : " << this << endl;
}

template<class T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& p) :
  ReferenceCounter(p), pointee(p.pointee)
{
  cout << "SmartPtr CopyCtor : ref = "<< &p <<endl;
  cout << "SmartPtr CopyCtor by ref called at : " << this  << endl;
}

template<class T>
SmartPointer<T> SmartPointer<T>::operator=(const SmartPointer<T>& p)
{
  cout << " SmartPtr = used called at : " << this << endl;
  if (this != &p)
  {
    if (1 == *counter)
      delete pointee;
    // Cant cast on lhs, use double pointer to assign
    // otherwise you take a copy of the value and change this which
    // is pointless (pun intended)
    T** pointee_temp = (T**) &pointee;
    *pointee_temp = p.pointee;
    ReferenceCounter::operator=(p);
  }
  return *this;
}

template<class T>
SmartPointer<T>::~SmartPointer()
{
  cout << "SmartPtr destructor called at : " << this << endl;
  if (1 == *counter)
    delete pointee;
}
#endif
