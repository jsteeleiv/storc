/*
 * cerebr4l 2024
 */

#include "storc.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/_endian.h>
#include <sys/socket.h>

#define EXIT_OKAY 0
#define EXIT_FAIL -1

int main(int argc, char **argv) {

  char *host;
  int s; // stream?, socket?, service?
  int16_t port;
  struct sockaddr_in sock;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return EXIT_FAIL;
  }

  host = argv[1];
  port = atoi(argv[2]);

  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    perror("socket");
    return EXIT_FAIL;
  }
  sock.sin_family = AF_INET;
  sock.sin_port = htons(PROXYPORT);
  sock.sin_addr.s_addr = inet_addr(PROXY);

  if (connect(s,
              (struct sockaddr *)&sock, // typecasting the reference
              sizeof(sock)) != 0) {
    perror("connect");
    return EXIT_FAIL;
  }
  printf("connection successful\n");
  close(s);
  return EXIT_OKAY;
}
