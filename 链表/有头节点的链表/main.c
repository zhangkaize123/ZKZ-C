//
//  main.c
//  有头节点的链表
//
//  Created by 张凯泽 on 16/6/6.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef enum stoporrun
{
    KisStop,
    KisRun
    
} StopOrRun;
//定义链表结构体
struct llist{
    int index;
    int num;
    struct llist * next;
};
typedef struct llist note;
typedef note* LList;
//创建节点
LList creatHeadLList(int array[],int len)
{
    LList head, ptr,ptr1;
    head = (LList)malloc(sizeof(note));
    if (!head) {
        printf("创建头节点失败\n");
        return NULL;
    }
    head ->next = NULL;
    ptr1 = head;
    for (int index = 0; index <len; index++) {
        ptr= (LList)malloc(sizeof(note));
        if (!ptr) {
            printf("创建节点失败\n");
            return NULL;
        }
        ptr ->next = NULL;
        ptr ->index = index;
        ptr ->num = array[index];
        head ->next = ptr;
        head = head ->next;
    }
    return ptr1;
}
//链表的显示
void ShowLList(LList head)
{
    if (!head) {
        return;
    }
    LList ptr = head ->next;
    while (ptr) {
        printf("%p------%d\n",ptr,ptr ->num);
        ptr = ptr ->next;
        
    }
}
int main(int argc, const char * argv[]) {
    
    int arr1[5]={16,16,45,4};
    int arr2[6]= {6,7,8,9,10,11};
    
    LList head1 = creatHeadLList(arr1, 4);
    ShowLList(head1);
    //LList head3 = FindLList(head1, 2);
    LList head4 = DeleteRepeatLList(head1, 0);
    printf("删除重复结构体之后显示\n");
    ShowLList(head4);
    //LList head2 = DeleteRepeatLList(head1, 3);
    return 0;
}
