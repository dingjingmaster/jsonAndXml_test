/*************************************************************************
    > File Name: Stream_socket.c
    > Author: DingJing
    > Mail: dingjing@live.cn
    > Created Time: 2016年11月15日 星期二 10时55分21秒
 ************************************************************************/
#include <unistd.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    int ret = 0;
    int serv_sock = 0;
    
    serv_sock = socket(AF_UNIX, SOCK_STREAM, 0);                              //创建流式本地套接字;
    if(-1 == serv_sock)
    {
        perror("socket error:");
        exit(1);
    }

    struct sockaddr_un serv_addr;
    
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, "./unix_socket");
    unlink("./unix_socket");
    ret = bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));   //为本地套接字绑定路径;
    
    if(-1 == ret)
    {
        perror("bind error:");
        exit(1);
    }

    ret = listen(serv_sock, SOMAXCONN);                                       //设置上限      
    
    if(-1 == ret)
    {
        perror("listen error:");
        exit(1);
    }

    int clie_socket;
    struct sockaddr_un clie_addr;
    int clie_addr_len = sizeof(clie_addr);
    
    memset(&clie_addr, 0, clie_addr_len);
    clie_socket = accept(serv_sock, (struct sockaddr*)&clie_addr, &clie_addr_len);               //监听
    
    if(-1 == clie_socket)
    {
        perror("accept error:");
        exit(1);
    }

    char BUF[BUFSIZ] = {0};
    while(1)
    {
        ret = read(clie_socket, BUF, sizeof(BUF));
        {
            if(ret <= 0)
            {
                break;
            }
        }

        printf("%s\n", BUF);

        for(int i = 0; i < ret; ++i)
        {
            BUF[i] = toupper(BUF[i]);
        }

        ret = write(clie_socket, BUF, strlen(BUF));
        {
            if(-1 == ret)
            {
                perror("write error:");
                exit(1);
            }
        }

        memset(BUF, 0, sizeof(BUF));
    }

    return 0;
}
