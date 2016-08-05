//
//  main.c
//  链表创建递归函数
//
//  Created by 张凯泽 on 16/6/14.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct link
{
    int data;
    struct link * next;
};
typedef struct link Link;
typedef Link*  Note;
//创建结构体递归函数
Note Create_Link(int * array,int len,int pos)
{
    Note head;
    if (pos == len) {
        return NULL;
    }else{
        head = (Note)malloc(sizeof(Link));
        if (!head) {
            return NULL;
        }
        head ->data = array[pos];
        head ->next = Create_Link(array, len, pos+1);
        
    }
    return head;
}
//输出函数
void PrintLink(Note head)
{
    if (head != NULL) {
       
        PrintLink(head ->next);
         printf("%d\n",head ->data);
    }
}
int main(int argc, const char * argv[]) {
    int arr[6] = {1,2,3,4};
    Note head = Create_Link(arr, 4, 0);
    PrintLink(head);
    return 0;
}
