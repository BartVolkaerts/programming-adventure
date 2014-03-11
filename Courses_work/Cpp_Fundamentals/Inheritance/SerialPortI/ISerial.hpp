#ifndef ISERIAL_H
#define ISERIAL_H

#include <iostream>

class ISerial {
  public:
    virtual int connect() = 0;
    virtual void disconnect() = 0;

    virtual int recvData(char *, int) = 0;
    virtual int sendData(char *, int) = 0;
};

#endif
