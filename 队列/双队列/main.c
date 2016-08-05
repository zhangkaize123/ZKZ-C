//
//  main.c
//  双队列
//
//  Created by 张凯泽 on 16/6/12.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#define MAXQUEUE 6
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
//在队列前存数据
int enqueue_front(int value)
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
//在队列后存数据
int enqueue_real(int value)
{
    if (real == -1) {
        real = MAXQUEUE;
    }
    //real = MAXQUEUE;
    if (real -1 == front || (real == -1 && front <= 0) ) {
        return -1;
    }
    real --;
    queue[real] = value;
    
    return 0;
}
//在队列(头部)取数据
int dequeue_front()
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
//在队列(尾部)取数据
int dequeue_real()
{
    int temp;
    if (real == front) {
        return -1;
    }
    temp = queue[real];
    real --;
    if (real < 0 && front != -1) {
        real = MAXQUEUE - 1;
    }
    
    return temp;
}

int main(int argc, const char * argv[]) {
    int input_list[6] = {1,2,3,4,5,6};
    
    int out_list[6];
    int select;
    int i,temp,pos = 0;
    for (i = 0; i<6; i++) {
        enqueue_real(input_list[i]);
    }
    while (real != front) {
        printf("[1]从后取出,[2]从前取出\n");
        scanf("%d",&select);
        switch (select) {
            case 1:temp = dequeue_real();
                out_list[pos++] = temp;
                break;
                
            default:
                temp = dequeue_front();
                out_list[pos++]= temp;
                break;
        }
    }
    
    for (i = 0; i<6; i++) {
        printf("************** = %d\n",input_list[i]);
    }
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    for (i = 0; i<6; i++) {
        printf("---------- = %d\n",out_list[i]);
    }
    
    return 0;
}
