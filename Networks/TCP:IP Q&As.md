# TCP/IP

### Basics

> What happens when you type google.com into your browser and press enter?

TADA (magic happens) it shows the Google homepage :)

- [DNS] browser asks OS for server's IP. OS can either use one from cache or query the DNS server for a DNS lookup.
- [TCP] browser establishes a TCP connection with the server (3 way handshake, SYN, SYN/ACK, ACK). Routers and Switches will help find the server.
- [SSL/TLS] browser asks SSL certificate from server and initiate SSL handshake.
- [HTTP] browser sends an HTTP request through the TCP connection.
- [HTTP] browser receives an HTTP response and may close the TCP connection, or reuse it for requests later on.
- [HTTP] browser checks the status code of the HTTP response (2xx->success, 3xx->redirection, 4xx->client error, 5xx->server error)
- [HTTP] finally browser renders the HTTP response to user.

> What is OSI 7 layers and list some most popular protocols that run on them?

- 7. 应 - Application (Provides functions needed by users) - HTTP, HTTPS, FTP, DNS, SMTP
- 6. 表 - Presentation (Converts different representations)
- 5. 会 - Session (Manages task dialogs)
- 4. 传 - Transport (Provides end-to-end delivery) - TCP, UDP
- 3. 网 - Network (Sends packets over multiple links) - IP, ICMP
- 2. 数 - Data link (Sends frames of information) - MAC
- 1. 物 - Physical (Sends bits as signals) - Ethernet, IEEE 802.11 (Wi-Fi)


> What is Router?

TODO


> What is Switch?

TODO


### IP Layer

> What fields are in IP header?

TTL, Protocol(TCP, UDP, ICMP...), header checksum, **source/destination address**, ip options, etc. 
- IP header
![IP header](https://github.com/xiaotdl/Docs/blob/master/Networks/images/ip_header.png)


> What fields are in ICMP header?

type, code, checksum
![ICMP header](https://github.com/xiaotdl/Docs/blob/master/Networks/images/icmp_header.png)


> Compare ping vs. traceroute?

TODO



## TCP Layer

> What fields are in TCP header?

**source/destination port**, sequence/acknowledgement number, TCP flags, checksum, tcp options, etc.
- TCP header
![TCP header](https://github.com/xiaotdl/Docs/blob/master/Networks/images/tcp_header.png)


> Explain TCP State Transition Diagram (a.k.a. TCP Finite State Machine) && TCP Socket Life Cycle? TCP connection establishment (three-way handshakes)? TCP connection release (four-way handshakes?

- TCP State Transition Diagram ([RFC793](http://www.cs.northwestern.edu/~agupta/cs340/project2/TCPIP_State_Transition_Diagram.pdf)) && TCP Socket Life Cycle
![TCP Socket Life Cycle](https://github.com/xiaotdl/Docs/blob/master/Networks/images/tcp_socket_life_cycle.jpg)

- Client Socket API  
![Client Socket API](https://github.com/xiaotdl/Docs/blob/master/Networks/images/client_socket_api.png)

- Server Socket API
![Server Socket API](https://github.com/xiaotdl/Docs/blob/master/Networks/images/server_socket_api.png)


> What fields are in UDP header?

**source/destination port**, length, checksum
- UDP header  
![UDP header](https://github.com/xiaotdl/Docs/blob/master/Networks/images/udp_header.png)
