/*************************************************************************
    > File Name: service.c
    > Author: DingJing
    > Mail: dingjing@live.cn
    > Created Time: 2016年11月15日 星期二 14时12分39秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

int main(int argc, char* argv[])
{
    int serv_sock;
    int ret;

    serv_sock = socket(AF_UNIX, SOCK_DGRAM, 0);                         //报式协议socket
    if(-1 == serv_socket)
    {
        printf("socket error:");
    }

    struct sockaddr_un serv_adr;
    serv_addr.sun_family = AF_UNIX;
    ret = strcpy(serv_addr.sun_path, "./unixsocket");
   
    if(-1 == ret)
    {
        perror("strcpy error:");
        exit(1);
    }

    unlink("./unixsocket");
    ret = bind(serv_socket, &serv_addr, sizeof(serv_addr));             //绑定服务器地址

    if(-1 == ret)
    {
        perror("bind error:");
        exit(1);
    }

    char BUF[BUFSIZ] = {0};

    while(1)
    {
        recvfrom(:);

    }

    return 0;
}
