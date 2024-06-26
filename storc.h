/*
 * cerebr4l 2024
 */

#include <arpa/inet.h>
#include <assert.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PROXY "127.0.0.1"
#define PROXYPORT 9050

struct proxy_request {
  uint8_t vn; // version number <4>
  uint8_t cd; // command code <1>
  uint16_t dstport;
  uint32_t dstip;
  const char *userid; // should I limit to 8 bits?
};

struct proxy_response {
  uint8_t vn;
  uint8_t cd;
  uint16_t dstport;
  uint32_t dstip;
  const char *result; // should I even use this?
};

typedef struct proxy_request Req;
typedef struct proxy_response Res;
