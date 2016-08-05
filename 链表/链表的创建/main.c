//
//  main.c
//  链表的创建
//
//  Created by 张凯泽 on 16/6/5.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>//使用 malloc 或者 free 导入库
struct llinst{
    int num;
    struct llinst * next;
};
typedef struct llinst note;
typedef  note* LList;
//创建链表
LList CreatLList(int array[],int len)
{
    LList head,ptr,ptr1;
    head =(LList) malloc(sizeof(note));
    
    if (!head) {
        printf("申请头节点失败\n");
        return NULL;
    }
    head ->next = NULL;
    head ->num = array[0];
    ptr = head;
    for (int index = 1; index<len; index++) {
        ptr1 =(LList)malloc(sizeof(note));
        if (!ptr1) {
            printf("申请节点失败\n");
            return NULL;
        }
        ptr1 ->next = NULL;
        ptr1 ->num = array[index];
        ptr ->next = ptr1;
        ptr = ptr ->next;
        
    }
    return head;
}
//链表的显示
void ShowLList(LList head)
{
    if (!head) {
        return;
    }
    LList ptr = head;
    while (ptr) {
        printf("%p------%d\n",ptr,ptr ->num);
        ptr = ptr ->next;
        
    }
}
//链表的链接
LList ContectLList(LList ptr1,LList ptr2)
{
    LList head = ptr1;
    while (ptr1 ->next) {
        ptr1 = ptr1 ->next;
    }
    ptr1 ->next = ptr2;
    return head;
}
//删除节点
//第一个节点，最后一个节点，中间节点
LList deleteLList(LList head,int deleteIndex)//结构体中储存的值
{
    
    //只有头节点
    if (head ->next == NULL) {
        free(head);
        return NULL;
    }
    //删除的是head节点
    if (head ->num == deleteIndex) {
        LList ptr = head ->next;
        free(head);
        return ptr;
        
    }
    //中间节点|最后节点
    LList ptr = head;
    LList previous,next1;
    while (ptr ->next) {
        previous = ptr;
        if (ptr ->next ->num == deleteIndex) {
            next1 = ptr ->next ->next;//ptr ->num = 2  ptr ->next 是最后一个
            if (next1 == NULL) {
                printf("指向的是最后一结构的下一个\n");
                next1 = NULL;
            }
            previous ->next = next1;
            free(ptr ->next);
            return head;
        }
        ptr = ptr ->next;
        
    }
    
    return head;
}
//链表的插入
/**
 head 代表 头节点
 ptr  代表在这个节点之前插入。
 num  代表插入节点的num的值。
 */
LList insertLList(LList head,LList ptr,int num)
{
    //创建插入链表的数据
    LList inserList = (LList)malloc(sizeof(note));
    if (!inserList) {
        printf("插入链表的数据创建结构体失败\n");
        return head;
    }
    inserList ->next = NULL;
    inserList ->num = num;
    if (!ptr) {//当 ptr 为NULL的时候在头节点之前插入。
        inserList ->next = head;
        return inserList;
    }else{
        if (ptr ->next == NULL) {////如果ptr不为NULL就在ptr之后插入
            ptr ->next = inserList;
            //return head;
        }else if (ptr == head)//如果ptr为头节点
        {
            LList ptrNext = head ->next;
            head ->next = inserList;
            inserList ->next = ptrNext;
            //return head;
        }else{//插入到中间节点
            
            LList ptr1 = ptr ->next;
            ptr ->next = inserList;
            inserList ->next = ptr1;
            //return head;
        
        }
        
    }
    return head;
}
//释放链表
void freeLList(LList head)
{
    LList ptr = head;
    LList freePtr;
    while (ptr) {
        freePtr = ptr;
        ptr = freePtr ->next;
        free(freePtr);
    }
}
//链表结构的反转
LList invertLList(LList head)
{
    
    LList mid,last;
    mid = NULL;
    while (head) {
        last = mid;
        mid = head;
        head = head ->next;
        mid ->next = last;
        
    }
    return mid;
}
int main(int argc, const char * argv[]) {

    int arr1[5]={1,2,3};
    int arr2[6]= {6,7,8,9,10,11};
    
   LList head1 = CreatLList(arr1, 3);
    ShowLList(head1);
    //LList head2 = CreatLList(arr2, 6);
    //printf("链表2\n");
    //ShowLList(head2);
   // LList head = ContectLList(head1,head2);
    //printf("链表连接后后\n");
    //ShowLList(head);
   //LList deleteHead = deleteLList(head1, 3);
    //printf("删除节点\n");
    //ShowLList(deleteHead);
   // LList head3 = insertLList(head1, NULL, 6);
    //LList head4 = insertLList(head1, head1->next->next, 8);
    //printf("插入节点之后\n");
    //ShowLList(head4);
    //freeLList(head1);
    LList head4 = invertLList(head1);
    printf("反转以后的链表\n");
    ShowLList(head4);
    return 0;
}
