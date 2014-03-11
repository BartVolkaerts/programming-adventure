#ifndef SRECPARSER_H
#define SRECPARSER_h

#include <stdint.h>

#define INVALID_VENDOR -1
#define INVALID_TYPE -2
#define INVALID_CHECKSUM -3

struct srec {
  uint8_t type;
  uint8_t size;
  uint32_t address;
  uint8_t *data;
  uint8_t checksum;
};

uint8_t getRecType(const char* rdata);
uint8_t getRecSize(const char* rdata);
uint32_t getRecAddress(const char* rdata, uint8_t type);
uint8_t getRecChecksum(const char* rdata);

#endif
