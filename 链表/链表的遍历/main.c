//
//  main.c
//  链表的遍历
//
//  Created by 张凯泽 on 16/6/4.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
struct llist{
    int num;
    struct llist * next;
};
typedef struct llist note;
typedef note* LList;
//创建节点
LList CreatLList()
{
    LList head,ptr,ptr1;
    head =(LList)malloc(sizeof(note));
    if (!head) {
        printf("创建头节点失败\n");
        return NULL;
    }
    head ->next = NULL;
    printf("请输入编号:");
    scanf("%d",&head ->num);
    ptr = head;
    for (int index = 0; index<6; index++) {
        ptr1 = (LList)malloc(sizeof(note));
        if (!ptr1) {
            printf("创建节点失败\n");
            return NULL;
        }
        ptr1 ->next = NULL;
        printf("请输入编号:");
        scanf("%d",&ptr1 ->num);
        ptr ->next = ptr1;
        ptr = ptr ->next;//让 ptr 指向下一个节点
    }
    return head;
    
}
void* FindLList1(LList head, int num)
{
    if (num<0) {
        return NULL ;
    }
    LList  ptr = head;
    while (1) {
        if (!ptr) {
            printf("------未找到\n");
            return NULL;
        }
        if (ptr ->num == num) {
            printf("----%p-----%d\n",ptr,ptr ->num);
            return ptr;
        }
        
        ptr = ptr ->next;
        
        
    }
    
}

int main(int argc, const char * argv[]) {
   LList head =  CreatLList();
    printf("下边是遍历\n");
    void * n = FindLList1(head,7);
    if (n) {
        printf("----%d\n",((LList)n) ->num);
    }else{
        printf("未找到\n");
    }
    
    return 0;
}
