/*************************************************************************
    > File Name: read_xml.c
    > Author: DingJing
    > Mail: dingjing@live.cn
    > Created Time: 2016年11月15日 星期二 00时10分16秒
 ************************************************************************/

#include <stdio.h>
#include <mxml.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen("./china_weather.xml", "r");                                 //打开要读取的文件
    mxml_node_t *xml = mxmlLoadFile(NULL, fp, MXML_NO_CALLBACK);                  //xml载入内存
    
    mxml_node_t *city = NULL;                                                     //建立一个根节点
    city = mxmlFindElement(xml, xml, "city", NULL, NULL, MXML_DESCEND);           //根节点指向xml根节点

    while(city)                                                                   //循环从xml中读取信息并显示
    {
        printf("区名称:%s \n", mxmlElementGetAttr(city, "quName"));
        printf("省名称:%s \n", mxmlElementGetAttr(city, "pyName"));
        printf("城市名称:%s \n", mxmlElementGetAttr(city, "cityname"));
        printf("状态1:%s \n", mxmlElementGetAttr(city, "state1"));
        printf("状态2:%s \n", mxmlElementGetAttr(city, "state2"));
        printf("天气:%s \n" ,mxmlElementGetAttr(city, "stateDetailed"));
        printf("最低温度:%s \n", mxmlElementGetAttr(city, "tem1"));
        printf("最高温度:%s \n", mxmlElementGetAttr(city, "tem2"));
        printf("风力:%s \n\n", mxmlElementGetAttr(city, "windState"));

        city = mxmlFindElement(city, xml, "city", NULL, NULL, MXML_DESCEND);
    }

    return 0;
}
