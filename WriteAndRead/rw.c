/*************************************************************************
    > File Name: rw.c
    > Author: DingJing
    > Mail: dingjing@live.cn
    > Created Time: 2016年11月18日 星期五 19时08分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int wfd = 0;                                 //创建读文件描述符;
    int rfd = 0;
    int ret = 0;                                 //判断返回值，确定函数调用是否出问题;
    char buf[BUFSIZ] = {0};

    ret = unlink("./writeAndRead");
    if(-1 == ret)
    {
        perror("unlink error:");
        exit(1);
    }
    wfd = open("./writeAndRead", O_CREAT | O_RDWR | O_APPEND, 0777);
    if(-1 == wfd)
    {
        perror("open error:");
        exit(1);
    }

    while(1)
    {
        memset(buf, 0, sizeof(buf));
        ret = read(STDIN_FILENO, buf, sizeof(buf));
        if(-1 == ret)
        {
            perror("1 read error");
            exit(1);
        }

        ret = write(wfd, buf, strlen(buf));  //将缓冲区的信息写入文件; 
        if('!' == buf[0])
        {
            printf("finish!!!\n");
            break;
        }
        if(-1 == ret)
        {
            perror("write error:");
            exit(1);
        }

        memset(buf, 0, sizeof(buf));

        ret = lseek(wfd, 0, SEEK_SET);
        if(-1 == ret)
        {
            perror("lseek error:");
            exit(1);
        }
        putchar('\n');

        ret = read(wfd, buf, sizeof(buf));
        while(ret)         //将文件中的信息读出到缓冲区;
        {
            if(ret != 0)
            {
                if(buf[0] != 0)
                {
                    printf("%s\n", buf);
                }else
                {
                    break;
                }
            }else
            {
                printf("finish!!!\n");
                exit(1);
            }
        ret = read(wfd, buf, sizeof(buf));               //将文件中的信息读出到缓冲区;
        }
    }

    close(wfd);
    close(rfd);

    return 0;
}
