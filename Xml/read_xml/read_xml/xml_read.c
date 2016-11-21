/*************************************************************************
    > File Name: xml_read.c
    > Author: DingJing
    > Mail: dingjing@live.cn
    > Created Time: 2016年11月15日 星期二 01时14分07秒
 ************************************************************************/

#include <stdio.h>
#include <mxml.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen("./qq_read.xml", "r");                                                //打开文件

    mxml_node_t *xml = mxmlLoadFile(NULL, fp, MXML_NO_CALLBACK);                           //载入xml文件  根为xml
    mxml_node_t *pic = mxmlFindElement(xml, xml, "Pic", NULL, NULL, MXML_DESCEND);         //查找根元素 根xml下查找 "Pic"

    mxml_node_t *resurl = NULL;
    mxml_node_t *thumbnail = NULL;
    while(pic)                                                                             //循环打印内容
    {
        resurl = mxmlFindElement(pic, xml, "resurl", "md5", NULL, MXML_DESCEND);
        thumbnail = mxmlFindElement(pic, xml, "thumbnail", "md5", NULL, MXML_DESCEND);
        
        if(NULL == resurl)
        {
            printf("resurl == NULL");
        }else
        {
            printf("原图地址:%s MD5:%s\n", mxmlGetText(resurl, NULL), mxmlElementGetAttr(resurl, "md5"));
        }

        if(NULL == thumbnail)
        {
            printf("thumbnail == NULL");
        }else
        {
            printf("缩略图地址:%s MD5:%s\n", mxmlGetText(thumbnail, NULL), mxmlElementGetAttr(thumbnail, "md5"));
        }

        pic = mxmlFindElement(pic, xml, "Pic", NULL, NULL, MXML_DESCEND);
        putchar('\n');
    }

    fclose(fp);
    mxmlDelete(xml);

    return 0;
}
