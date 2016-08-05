//
//  main.c
//  使用链表创建双队列
//
//  Created by 张凯泽 on 16/6/12.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct queue{
    int data;
    struct queue * next;
};
typedef struct queue Queue;
typedef Queue * queue_link;
queue_link real = NULL;//队列尾
queue_link front = NULL;//队列头
//数据存入(尾部)队列
int enqueue_real(int value)
{
    queue_link queue = (queue_link)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("创建节点失败\n");
        return -1;
    }
    queue ->data = value;
    queue ->next = NULL;
    if (real == NULL) {
        front = queue;
    }else{
        real ->next = queue;
    }
    real = queue;
    return 0;
}
//数据存入(首部)
int enqueue_front(int value)
{
    queue_link queue = (queue_link)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("创建节点失败\n");
        return -1;
    }
    queue ->data = value;
   // queue ->next = NULL;
    if (front == NULL) {
        queue ->next = NULL;
        real = queue;
    }else{
        queue ->next = front;
    }
    front = queue;
    return 0;
}
//取数据
int dequeue()
{
    queue_link top;
    int temp;
    if (front != NULL) {
        top = front;
        temp = top ->data;
        front = front ->next;
        free(top);
        return temp;
    }else{
        return -1;
    }
    
}
int main(int argc, const char * argv[]) {
    int input_list[6] = {1,2,3,4,5,6};
    
    //int out_list[6];
    int select;
    int i,temp = 0;
    
    for (i = 0; i<6; i++) {
        printf("[1]从后存放,[2]从前边存放\n");
        scanf("%d",&select);
        switch (select) {
            case 1:
                enqueue_real(input_list[i]);
                break;
                
            default:
                enqueue_front(input_list[i]);
                break;
        }
    }
    for (i = 0; i<6; i++) {
        printf("************** = %d\n",input_list[i]);
    }
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    while ((temp = dequeue()) != -1) {
        printf("----------- = %d\n",temp);
    }
    
    
    Queue * q1 =(Queue*)malloc(sizeof(sizeof(Queue)));
    printf("&q1 = %p\n",&q1);
    printf("q1 = %p\n",q1);
    Queue **q2 = &q1;
    printf("*q2 = %p\n",*q2);
    printf("q2 = %p\n",q2);
    /*
     &q1 = 0x7fff5fbff7f8
     q1 = 0x100300010
     *q2 = 0x100300010
     q2 = 0x7fff5fbff7f8
     */
    return 0;
}
