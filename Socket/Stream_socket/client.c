/*************************************************************************
    > File Name: client.c
    > Author: DingJing
    > Mail: dingjing@live.cn
    > Created Time: 2016年11月15日 星期二 11时40分00秒
 ************************************************************************/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    if(2 != argc)
    {
        printf("Not enough argument!!!\n");
        exit(1);
    }

    int clie_socket;
    int ret;

    clie_socket = socket(AF_UNIX, SOCK_STREAM, 0);

    if(-1 == clie_socket)
    {
        perror("socket error:");
        exit(1);
    }

    struct sockaddr_un clie_addr;
    clie_addr.sun_family = AF_UNIX;
    strncpy(clie_addr.sun_path, "./unix_socket", sizeof("./unix_socket"));
    ret = connect(clie_socket, (struct sockaddr*)&clie_addr, sizeof(clie_addr));
    
    if(-1 == ret)
    {
        perror("socket error:");
        exit(1);
    }

    ret = write(clie_socket, argv[1], strlen(argv[1]));
    if(-1 == ret)
    {
        perror("write error:");
        exit(1);
    }

    char BUF[BUFSIZ] = {0};
    ret = read(clie_socket, BUF, sizeof(BUF));

    if(-1 == ret)
    {
        perror("read error:");
    }

    while(ret != 0)
    {
        for(int i = 0; i < ret; ++i)
        {
            putchar(BUF[i]);
        }
        //printf("%s\n", BUF);                              //不加换行无法读出，以后通信过程还是以直接读取数据比较好;
        memset(BUF, 0, sizeof(BUF));
        putchar('\n');
        ret = read(clie_socket, BUF, sizeof(BUF));
        
        if(-1 == ret)
        {
            perror("read error:");
            exit(1);
        }
    }

    close(clie_socket);
    
    exit(1);
}
