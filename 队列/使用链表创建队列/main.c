//
//  main.c
//  使用链表创建队列
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
//数据存入队列
int enqueue(int value)
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
   
    
    
    return 0;
}
