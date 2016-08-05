//
//  main.c
//  链表
//
//  Created by 张凯泽 on 16/6/3.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
struct llist{
    int num;
    char name[10];
    char address[50];
    struct llist * next;
};
typedef struct llist note;
typedef note* LList;
int main(int argc, const char * argv[]) {

    //LList ptr =(LList)malloc(sizeof(note));
   //struct llist * ptr1 =(struct llist*)malloc(sizeof(struct llist));

    LList head,ptr,ptr1;
    head = (LList)malloc(sizeof(note));
    if (!head) {
        printf("申请空间不成功\n");
        exit(1);
    }
    head ->next = NULL;
    ptr = head;
    printf("请输入编号:");
    scanf("%d",&ptr ->num);
    printf("请输入姓名:");
    scanf("%s",ptr ->name);
    printf("－－－－－头节点%p\n",head);
    for (int i = 0; i <2; i++) {
        
        ptr1 =(LList)malloc(sizeof(note));
        printf("-------%p\n",ptr1);
        if (!ptr1) {
            printf("--申请空间不成功\n");
            exit(1);
        }
        printf("请输入编号:");
        scanf("%d",&ptr1 ->num);
        printf("请输入姓名:");
        scanf("%s",ptr1 ->name);
        ptr1 ->next = NULL;
        ptr ->next = ptr1;
        ptr = ptr ->next;
    }
    //进行打印
    printf("----------------------进行打印\n");
    ptr = head;
    while (ptr !=NULL ) {
        printf("-------%p\n",ptr);
        printf("编号:%d---->姓名:%s\n",ptr ->num,ptr ->name);
       ptr = ptr ->next;
    }
    
    return 0;
}
