/*
 *    UDP server
 *    Author: Maarten Vandersteegen
 */

#ifndef   _UDP_SERVER_H
#define   _UDP_SERVER_H

#include <stdint.h>

struct __attribute__((packed)) Proto_hdr {
  uint32_t  type:8,
            node_id:24;
  uint16_t  nr_sensors;
  uint16_t  msg_len;
};

typedef   uint32_t    Sensortype;
#define   PORT        7412

#endif    /* _UDP_SERVER_H */
