#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "srecparser.h"

uint8_t getRecType(const char* rdata)
{
  if(rdata[0] != 'S')
    return INVALID_VENDOR;
  char type = rdata[1] - '0';
  if(type>9 || type < 0)
    return INVALID_TYPE;
  return type;
}

uint8_t getRecSize(const char* rdata)
{
  uint8_t size;

}

uint32_t getRecAddress(const char* rdata, uint8_t type)
{
}

uint8_t getRecChecksum(const char* rdata)
{
}

int main(int argc, char **argv)
{
  struct srec rec;
  const char *rdata = "S111003848656C6C6F20776F726C642E0A0042";
  rec.type = getRecType(rdata); 
  rec.size = getRecSize(rdata);


//  rec.address = getRecAddress(rdata);
//  rec.Checksum = getRecChecksum(rdata);

  return 0;
}
