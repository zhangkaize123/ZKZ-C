//
//  main.c
//  使用链表构建栈2
//
//  Created by 张凯泽 on 16/6/9.
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
Link stack1 = NULL;
Link stack2 = NULL;
//进栈函数
Link pushStack(Link stack,int value)
{
    Link note = (Link)malloc(sizeof(stack_list));
    if (note == NULL) {
        printf("创建链表节点失败\n");
        return NULL;
    }
    note ->data = value;
    note ->next = stack;
    stack = note;
    return stack;
}
void pushStack1(Link *stack,int value)
{
    Link note = (Link)malloc(sizeof(stack_list));
    if (note == NULL) {
        printf("创建链表节点失败\n");
        return;
    }
    note ->data = value;
    note ->next = *stack;
    *stack = note;
}

//出栈函数
Link popStack(Link stack,int *value)
{
    Link ptr;
    if (stack == NULL) {
        printf("以到栈底\n");
        *value = -1;
        return NULL;
    }else{
        ptr = stack;
        *value = ptr ->data;
        stack = stack ->next;
        free(ptr);
        return stack;
    }
}
int popStack1(Link *stack)
{
    Link pp = *stack;
    int temp;
    Link ptr;
    if (*stack == NULL) {
        return -1;
    }else{
        ptr = pp;
        pp = pp ->next;
        *stack = pp;
        temp = ptr ->data;
        free(ptr);
        
        return temp;
    }
    return 0;
    
}
//判断栈是否为空
int empty(Link stack)
{
    if (stack == NULL) {
        return -1;
    }else{
        return 0;
    }
}
int main(int argc, const char * argv[]) {
    Link stack3 =(Link) malloc(sizeof(sizeof(stack_list)));
    int arr[] = {1,2,3,6,5,8,36};
    int temp;
    for (int i = 0; i<7; i++) {
       // pushStack(stack1, arr[i]);
         //stack2 = pushStack(stack2, arr[i]+100);
        pushStack1(&stack3, arr[i]+100);
    }
//    printf("--%d\n",popStack1(&stack3));
//    printf("--%d\n",popStack1(&stack3));
    while (!empty(stack3)) {
        
        printf("temp = %d\n",popStack1(&stack3));
    }
    
//    while (!empty(stack2)) {
//       stack2 = popStack(stack2,&temp);
//        printf("temp = %d\n",temp);
//    }

    return 0;
}
