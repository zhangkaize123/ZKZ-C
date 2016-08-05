//
//  main.c
//  字符串
//
//  Created by 张凯泽 on 16/6/3.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//
//字符串的长度
int strLen(const char * s)
{
    int i = 0;
    for (int index = 0; s[index] != '\0'; index++) {
        i++;
    }
    return i;
}
#include <stdio.h>
#include <string.h>
//字符串的长度
int main(int argc, const char * argv[]) {
#pragma mark--zkz---字符串的长度
    char str2[4];
    char str[30] = {'q','w','e','r','t','t'};
    char * str1 = "fgegdgf";
    printf("---%d\n",strLen(str2));
    printf("---%d\n",strLen(str));
    printf("---%d\n",strLen(str1));
    printf("----------------------------------------------------\n");
    char string[100];
    char * sss = "ABCDEFGHIJ";//1.它与 char string[100] 唯一的不同点是在结束的时候加上了 '\0'
    /*
     //2.可变字符串(放到栈里边)栈里边放局部变量有几份变量就有几个内存空间
     char name[4] = "zkz";
     char name3[4] = "zkz";
     printf("name[4] = %p\n",name);//name[4] = 0x7fff5fbff79c
     printf("name3[4] = %p\n",name3);//name3[4] = 0x7fff5fbff798
     //不可变字符串     放到常量区且只有一份能存空间
     char *name1 = "zkz";
     char *name2 ="zkz";
     printf("name1=%p\n",name1);//name1 = 0x100000f86
     printf("name2=%p\n",name2);//name2 = 0x100000f86
     
     */
    for (int index = 0; index<10;index++) {
        string[index]= 65+index;
        
    }
    string[10]= '\0';
    printf("字符串的长度:%lu\n",strlen(string));//字符串的长度不包括 '\0'的长度
    printf("%s\n",string);
    printf("----------------------------------------------------\n");
    struct student{
        int age;
        char name[10];
    };
    printf("结构体的sizeof:%lu\n",sizeof(struct student));//字节数wei:16总是为元素中字节数最大数的倍数。

    return 0;
}
