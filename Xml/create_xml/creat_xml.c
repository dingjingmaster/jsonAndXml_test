/*************************************************************************
    > File Name: creat_xml.c
    > Author: DingJing
    > Mail: dingjing@live.cn
    > Created Time: 2016年11月14日 星期一 23时14分47秒
 ************************************************************************/

#include <stdio.h>
#include <mxml.h>

/*xml文件生成和解析：
 *
 *    关于xml文件的生成和解析需要用到第三方标准库 mxml ；
 *本程序基于mxml-2.9 需要对其进行安装；mxml低版本可能会
 *缺少一些相应库函数。
 *    在使用gcc进行编译的时候一定要指定-lmxml和-lpthread
 *否则无法完成编译。且一定先指定mxml。
 */

int main(int argc, char* argv[])
{
    mxml_node_t *xml = mxmlNewXML("1.0");                           //创建xml文件的声明部分  <?xml version = "1.0" encoding = "utf-8" ?>
    mxml_node_t *class = mxmlNewElement(xml, "class");              //创建整个xml文件的根节点 "class"
    mxml_node_t *teacher = mxmlNewElement(class, "teacher");        //创建"teacher"节点并加入到根节点"class"之下
    mxmlElementSetAttr(teacher, "name", "张三");                    //设置"teacher"属性为name = "张三"
    mxmlNewText(teacher, 0, "语文");                                //设置"teacher"文本为"语文"；

    mxml_node_t *student = mxmlNewElement(class, "student");        //创建"student"节点并加入到根节点 "class" 之下
    mxml_node_t *student1 = mxmlNewElement(student, "student1");    //创建"student1"节点并加入到"student"节点之下
    mxmlElementSetAttr(student1, "name", "小明");                   //设置"student1"属性为name = "小明"
    mxmlNewText(student1, 0, "学生1");                              //设置"student1"的文本为 "学生1"

    FILE *fp = fopen("./class.xml", "w");                           //创建并打开 class.xml 文件
    mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);                        //讲xml信息写入class.xml文件中进行保存

    fclose(fp);                                                     //关闭文件流
    mxmlDelete(xml);                                                //删除整个树形结构

    return 0;
}
