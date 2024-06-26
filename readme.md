# Storc
    serial tor client in c

An attempt to learn about tor, how it was built, how it works, and how it's used.

<!-- TODO: fill in as I go  -->

## notes

using [socks4](https://www.openssh.com/txt/socks4.protocol) rfc protocol
    rfc == requests for comments

request packet format:

                 +----+----+----+----+----+----+----+----+----+----+....+----+
                 | VN | CD | DSTPORT |      DSTIP        | USERID       |NULL|
                 +----+----+----+----+----+----+----+----+----+----+....+----+
 \# of bytes:	    1    1      2              4           variable        1
   VN = protocol version # <4>
   CD = socks command code <1> for connect request

response packet format:

                +----+----+----+----+----+----+----+----+
                | VN | CD | DSTPORT |      DSTIP        |
                +----+----+----+----+----+----+----+----+
 \# of bytes:	   1    1      2              4

Network Byte Order:
    MSB most significant bits come first

htons() reverses port
inet_addr() reverses ip addr



