# HTTP

### Basics

> What is HTTP, i.e. Hypertext Transfer Protocol?

HTTP is a networking protocol, which is mostly used as the foundation of data communication for the World Wide Web.


> What is an [**HTTP Request message**](http://www-scf.usc.edu/~csci571/Special/Tutorials/wireshark_html/wireshark.html)?

The HTTP request message consists of the following:
- A Request-line (method resource HTTP/version)
- Zero or more header (General|Request|Entity) fields followed by CRLF
- An empty line (i.e., a line with nothing preceding the CRLF) indicating the end of the header fields
- Optionally a message-body
```
GET /hello.htm HTTP/1.1
User-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)
Host: www.tutorialspoint.com
Accept-Language: en-us
Accept-Encoding: gzip, deflate
Connection: Keep-Alive
```


> What are **HTTP request methods**?

- GET  - requests the specified resource.
- HEAD - same as GET method, but returns only the response headers
- POST - sends data to the server to create a new entity. Often used when uploading a file, or submitting a completed web form.
- PUT  - similiar to POST, but used to replace an existing entity
- PATCH - similiar to PUT, but used to update only certain fields of an existing entity
- DELETE - deletes the specified resource
- OPTIONS, CONNECT, TRACE - rarely used


> What is an [**HTTP Response message**](https://ask.wireshark.org/questions/38582/unreadable-data-in-follow-tcp-stream)?

- A Status-line (HTTP/version StatusCode)
- Zero or more header (General|Response|Entity) fields followed by CRLF
- An empty line (i.e., a line with nothing preceding the CRLF) indicating the end of the header fields
- Optionally a message-body
```
HTTP/1.1 200 OK
Date: Mon, 27 Jul 2009 12:28:53 GMT
Server: Apache/2.2.14 (Win32)
Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT
Content-Length: 88
Content-Type: text/html
Connection: Closed
<html>
<body>
<h1>Hello, World!</h1>
</body>
</html>
```


> What are [**HTTP Status Codes**](http://www.tutorialspoint.com/http/http_status_codes.htm), i.e. HTTP Response Code?

- 1xx: Informational
- 2xx: Success
  * 200 OK
  * 201 Created
  * 202 Accepted
- 3xx: Redirection
- 4xx: Client Error
  * 400 Bad Request, server didn't understand the request
  * 401 Unauthorized, the requested page needs a username and a password
  * 403 Forbidden, access is forbidden
  * 404 Not Found, server can't find the requested page
- 5xx: Server Error
  * 500 Internal Server Error, the request is not completed, the server meets unexpected condition
  * 503 Service Unavailable, the request is not completed, the server is temporarily overloading or down


> What are [**HTTP headers**](http://www.tutorialspoint.com/http/http_header_fields.htm)?

There are four types of HTTP headers:
- General-header: applicable to both request and response msg
  * Date: Mon, 27 Jul 2009 12:28:53 GMT
  * Connection: keep-alive
  * Cache-control: no-cache
- Client Request-header: only applicable to request msg
  * Accept: text/plain
  * Accept-Encoding: compress, gzip
  * Authorization: BASIC Z3Vlc3Q6Z3Vlc3QxMjM=, where username:password is encoded in base 64
  * User-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)    (Browser type and OS type)
- Server Response-header: only applicable to response msg
  * Accept-Ranges: bytes
  * Server: Apache/2.2.14 (Win32)
  * Set-Cookie: name1=value1,name2=value2; Expires=Wed, 09 Jun 2021 10:18:14 GMT
- Entity-header: defines meta infomation about the entity body
  * Content-Length: 3495
  * Expires: Thu, 01 Dec 1994 16:00:00 GMT
  * Last-Modified: Tue, 15 Nov 1994 12:45:26 GMT


> What is **HTTP session**?

- HTTP session is a sequence of HTTP request-and-response transactions.
- An HTTP client initiates a request. It establishes a TCP connection to a particular port (typically 80) on a host. An HTTP server listening on that port waits for a client's request message. Upon receiving the request, the HTTP server sends back a status line, such as "HTTP/1.1 200 OK", along with headers and a message, the body of message is perhaps the requested resource, an error message, or some other info.


> What is **persistent connections**?

In HTTP/0.9 and HTTP/1.0, the connection is closed after a single request/response pair.
In HTTP/1.1 a keep-alive mechanism was introduced, where a connection could be reused for more than one request.


> What is URLs in HTTP, i.e. Uniform Resource Locator?

URLs identifies resources that hosted on servers.


> What is cURL in HTTP?

cURL is a command line tool that is available on all major OS.
```
➜  ~  curl --include -X GET http://google.com
HTTP/1.1 301 Moved Permanently
Location: http://www.google.com/
Content-Type: text/html; charset=UTF-8
Date: Fri, 06 May 2016 05:56:18 GMT
Expires: Sun, 05 Jun 2016 05:56:18 GMT
Cache-Control: public, max-age=2592000
Server: gws
Content-Length: 219
X-XSS-Protection: 1; mode=block
X-Frame-Options: SAMEORIGIN

<HTML><HEAD><meta http-equiv="content-type" content="text/html;charset=utf-8">
<TITLE>301 Moved</TITLE></HEAD><BODY>
<H1>301 Moved</H1>
The document has moved
<A HREF="http://www.google.com/">here</A>.
</BODY></HTML>
```


> Explain the difference between **stateless** and **stateful** protocols. Which type of protocol is HTTP?

- A stateless communications protocol treats each request as an independent transaction. It therefore does not require the server to retain any session, identity, or status information spanning multiple requests from the same source. Similarly, the requestor can not rely on any such information being retained by the responder.

- In contrast, a stateful communications protocol is one in which the responder maintains “state” information (session data, identity, status, etc.) across multiple requests from the same source.

- **HTTP is a stateless protocol**. HTTP does not require server to retain information or status about each user for the duration of multiple requests.
Some web servers implement states using different methods (using cookies, custom headers, hidden form fields etc.). However, in the very core of every web application everything relies on HTTP which is still a stateless protocol that is based on simple request/response paradigm.


> What is the HTTP version we are using and what's the latest version?

We are using HTTP/1.1; The latest version is HTTP/2



> List the key advantages of HTTP/2 as compared to HTTP/1.1?

HTTP/2 provides decreased latency to improve page load speed by supporting:
- Data compression of HTTP headers
- Server push technologies
- Loading of page elements in parallel over a single TCP connection
- Prioritization of requests


> What is HTTP cookie?

- An HTTP cookie is a small piece of data sent from a website and stored in the user's web browser (scalable) while the user is browsing. Every time the user loads the website, the browser sends the cookie back to the server to notify the user's previous activity.
- Cookies were designed to be a reliable mechanism for websites to remember stateful information (such as items added in the shopping cart in an online store) or to record the user's browsing activity (including clicking particular buttons, logging in, or recording which pages were visited in the past).
- Cookies can also store passwords and form content a user has previously entered, such as a credit card number or an address.

