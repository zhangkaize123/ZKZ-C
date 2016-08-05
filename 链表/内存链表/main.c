//
//  main.c
//  内存链表
//
//  Created by 张凯泽 on 16/6/12.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct link
{
    int data;
    struct link * next;
};
typedef struct link Note;
typedef Note* Link;
//链表节点的内存释放
void freenode(Link * memery,Link ptr)
{
    ptr ->next = (*memery);
    (*memery) = ptr;
}
//打印内存链表
void printmemery(Link memery)
{
    Link ptr = memery;
    while (ptr != NULL) {
        printf("%d\n",ptr ->data);
        ptr = ptr ->next;
    }
}
//链表节点的内存释放
Link notealloc(Link * memery)
{
    Link top;
    if ((*memery) != NULL) {
        top = *memery;
        *memery = (*memery) ->next;
        top ->next = NULL;
        
    }else{
        top =(Link)malloc(sizeof(Note));
        printf("----------\n");
        if (top == NULL) {
            printf("创建内存节点失败\n");
            return NULL;
        }
        top ->next = NULL;
    }
    return top;
}
//创建循环链表
Link creatLink(int *array ,Link * memery, int len)
{
    Link head,ptr1;
    head = notealloc(memery);
    head ->next = NULL;
    ptr1 = head;
    for (int i = 0; i<len; i++) {
        Link ptr = notealloc(memery);
        ptr ->data = array[i];
        head ->next = ptr;
        head = head ->next;
        
    }
    head ->next = ptr1;
    return ptr1;
}
//循环列表打印
void printLink(Link head)
{
    Link ptr = head;
    do {
        head = head ->next;
        printf("循环链表打印:%d\n",head ->data);
    } while (ptr != head ->next);
}
//释放整条循环链表
void freeLink(Link head,Link *memery)
{
    Link secondLink = head ->next;
    head ->next = *memery;
    *memery = secondLink;
}

int main(int argc, const char * argv[]) {
    
    Link memery = NULL;//内存链表的头节点
    //Link head = NULL;//循环链表头节点
    Link note;
    int arr[6] = {1,2,3,4,5,6};
    for (int i = 0; i<8; i++) {
        note = (Link)malloc(sizeof(Note));
        if (note == NULL) {
            printf("创建节点失败\n");
            exit(1);
        }
        note ->next = NULL;
        note ->data = 100+arr[i];
        freenode(&memery, note);
    }
    //打印内存链表
    printmemery(memery);
    //创建循环链表
   Link head = creatLink(arr, &memery, 6);
    //打印循环链表
    printLink(head);
    freeLink(head, &memery);
    //int arr2[8] = {7,5,6,4,5,3,7,9};
    printf("&&&&&&&&&&&&&&&&&\n");
        printmemery(memery);
    return 0;
}
