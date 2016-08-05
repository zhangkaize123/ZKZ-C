//
//  main.c
//  队列
//
//  Created by 张凯泽 on 16/6/12.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#define MAXQUEUE 10
int queue[MAXQUEUE];
int real = -1;
int front = -1;
//在队列中存放数据
int enqueue(int value)//
{
    if (real + 1 == front || (real == MAXQUEUE-1 && front <= 0 ) ) {
        return -1;
    }
    real ++;
    if (real ==MAXQUEUE) {
        real = 0;
    }
    queue[real] = value;
    return 0;
    
}
//在队列中取数据
int dequeue()
{
    if (front == real) {
        return  -1;
    }
    front ++;
    if (front == MAXQUEUE) {
        front = 0;
    }
    return queue[front];
    
}
int main(int argc, const char * argv[]) {

    
    
    
    return 0;
}
