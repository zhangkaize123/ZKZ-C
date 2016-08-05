//
//  main.c
//  使用链表构建栈
//
//  Created by 张凯泽 on 16/6/8.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct stack_note{
    int data;
    struct stack_note * next;
    
};
typedef struct stack_note stack_list;
typedef stack_list* Link;
Link stack = NULL;
//进栈函数
int pushStack(int value)
{
    Link link = (Link)malloc(sizeof(stack_list));
    if (!link) {
        printf("创建节点失败\n");
        return -1;
    }
    link ->data = value;
    link ->next =stack;
    stack = link;
    return 0;
}
//出栈函数
int popStack()
{
    if (stack != NULL) {
        Link pre = stack;
        stack = stack ->next;
        int aa = pre ->data;
        free(pre);
        return aa;
    }else{
        return -1;
    }
    
}
//检查栈是否为空
int empty()
{
    if (stack == NULL) {
        return 1;
    }else{
        return 0;
    }
}
int main(int argc, const char * argv[]) {
    
    int arr[] ={1,2,3,4,5,6};
    for (int index = 0; index<6; index ++) {
       int a = pushStack(arr[index]);
        if (a == -1) {
            printf("创建链表失败\n");
            break;
        }
    }
   int aa1 = popStack();
    int aa2 = popStack();
    printf("aa1 = %d\n",aa1);
    printf("aa2 = %d\n",aa2);
    return 0;
}
