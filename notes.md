# 0verview

## sockets

using [socks4](https://www.openssh.com/txt/socks4.protocol)-rfc protocol
>rfc == requests for comments

request packet format:

     +----+----+----+----+----+----+----+----+----+----+....+----+
     | VN | CD | DSTPORT |      DSTIP        | USERID       |NULL|
     +----+----+----+----+----+----+----+----+----+----+....+----+
       1    1      2              4           variable        1

   VN = protocol version # <4>
   CD = socks command code <1> for connect request

response packet format:

    +----+----+----+----+----+----+----+----+
    | VN | CD | DSTPORT |      DSTIP        |
    +----+----+----+----+----+----+----+----+
      1    1      2              4

Network Byte Order:
    MSB most significant bits come first?

htons() reverses port
inet_addr() reverses ip addr

### sockaddr_in struct

```c
/*
 * Socket address, internet style.
 */
struct sockaddr_in {
	__uint8_t       sin_len;
	sa_family_t     sin_family;
	in_port_t       sin_port;
	struct  in_addr sin_addr;
	char            sin_zero[8];
};
```
```c
/*
 * Internet address (a structure for historical reasons)
 */
struct in_addr {
	in_addr_t s_addr;
};
```

## using EXIT macros

The macros EXIT_SUCCESS and EXIT_FAILURE are defined in <stdlib.h> 
to represent these standard return values.
They are used with the exit function to terminate a program and return a status code.

EXIT_SUCCESS is typically defined as 0.
EXIT_FAILURE is typically defined as 1, although this can vary between systems.

_Why Use These Macros?_
Using EXIT_SUCCESS and EXIT_FAILURE instead of hardcoding numeric values (like 0 or 1) 
makes your code more readable and portable. 
It clearly indicates the intention of the exit status and ensures that your program adheres to 
the conventions expected by other programmers and the system.




