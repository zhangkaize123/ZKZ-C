//
//  main.c
//  循环链表
//
//  Created by 张凯泽 on 16/6/7.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef enum insertmodel
{
    KFirstModel,//在头节点之前插入
    KMiddleModel,//在中间位置插入
    KLastModel//在链表的结尾插入
    
}InsertModel;
struct llist{
    int data;
    struct llist * next;
};
typedef struct llist note;
typedef note * LList;
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
    head ->data = array[0];
    ptr1 = head;
    for (int index = 1; index <len; index++) {
        ptr= (LList)malloc(sizeof(note));
        if (!ptr) {
            printf("创建节点失败\n");
            return NULL;
        }
        ptr ->next = NULL;
        ptr ->data = array[index];
        head ->next = ptr;
        head = head ->next;
    }
    printf("-------%p\n",head);
    head ->next = ptr1;
    return ptr1;
}
//链表的显示
void ShowLList(LList head)
{
    if (!head) {
        return;
    }
    LList ptr = head;
    LList previousList,nextList;
    previousList = NULL;
    do {
        printf("-------------%d\n",head ->data);
//        nextList = previousList;
//        previousList = head;
        head = head ->next;
        //nextList = head ->next;
        //printf("pre = %p---head = %p---next = %p\n",previousList,head,nextList);
        
    } while (ptr != head);
}
//链表的插入
/**
 head：链表的头节点
 num:插入的链表的值
 ptr1:在哪个链表之前插入，如果ptr1为NULL时就在链表结尾插入.
 */
LList insertLList(LList head,int num,int ptr1)
{
    
    LList note = (LList)malloc(sizeof(note));
    if (!note) {
        printf("创建插入节点失败\n");
        return NULL;
    }
    note ->data = num;
    note ->next = NULL;
    //查找ptr1值所在链表的位置
    LList ptr2 = head;
    LList previousList,nextList;
    previousList = NULL;
    do {
        
        nextList = previousList;
        previousList = head;

        head = head ->next;
        if (head ->data == ptr1) {
            previousList ->next = note;
            note ->next = head;
            break;
        }
        nextList = head ->next;
        
    } while (ptr2 != head);
    
   
    
    return ptr2;
}
//链表的删除不允许删除第一个节点（头节点）
LList DeleteLList(LList head,int ptr)
{
    LList headList = head;
    LList preList,nextList;
    preList = NULL;
    do {
        
        preList = head;
        head = head ->next;
        nextList = head ->next;
        if (head ->data == ptr) {
            preList ->next = nextList;
            free(head);
            break;
        }
        //printf("pre = %p---head = %p---next = %p\n",preList,head,nextList);
    } while (headList != head);
    return headList;
}
int main(int argc, const char * argv[]) {
    
    int arr[] = {4,56,76,89,43};
    LList head = creatHeadLList(arr, 4);
    printf("**************\n");
    ShowLList(head);
    LList head2 = insertLList(head, 300, 4);
    printf("插入后的打印\n");
    ShowLList(head2);
    printf("删除之后\n");
    LList head3 = DeleteLList(head, 89);
    ShowLList(head3);
//    InsertModel IModel = KLastModel;
//    LList head1 = insertLList(head, 78,IModel,800);
//    printf("插入后的打印\n");
//    ShowLList(head1);
    return 0;
}
