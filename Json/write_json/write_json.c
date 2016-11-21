/*************************************************************************
    > File Name: write_json.c
    > Author: DingJing
    > Mail: dingjing@live.cn
    > Created Time: 2016年11月15日 星期二 09时48分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int main(int argc, char* argv[])
{
    cJSON *man1 = cJSON_CreateObject();             //创建一个空文档对象 { } 

    cJSON_AddItemToObject(man1, "name", cJSON_CreateString("郭豪"));
    cJSON_AddNumberToObject(man1, "age", 29);
    cJSON *array = NULL;
    array = cJSON_CreateArray();
    cJSON_AddItemToArray(array, cJSON_CreateString("LOL"));
    cJSON_AddItemToArray(array, cJSON_CreateString("老鸡"));
    cJSON_AddItemToObject(man1, "love", array);

    char *buf = cJSON_Print(man1);
    FILE *fp = fopen("write_json.json", "w");
    fwrite(buf, 1, strlen(buf), fp);

    free(buf);
    fclose(fp);
    cJSON_Delete(man1);

    return 0;
}
