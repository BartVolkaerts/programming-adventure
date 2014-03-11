#ifndef _REFERENCE_COUNTER_H_
#define _REFERENCE_COUNTER_H_

class ReferenceCounter
{
  protected:
    unsigned int* counter;
  public:
      ReferenceCounter();
      ReferenceCounter(const ReferenceCounter& r);
      // Destructor must be virtual, otherwise only the 
      // superclass destructor will be called. compiler doesnt care,
      // will just take the superclass, no virtual there, dont care
      // about childs just execute that one
      ReferenceCounter& operator=(const ReferenceCounter& r);
      virtual ~ReferenceCounter();
};


#endif
