//
//  main.c
//  数组与字符串
//
//  Created by 张凯泽 on 16/6/3.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    //1.内存静态分配
    int aa = 4;
    int scores1[5];
    scores1[aa]= 34;
    //结构体数组
    struct score{
        int Chinese;
        int Computer;
        double Match;//占用8个字节
        
    };
    float aaa ;//占用内存空间为 4 个字节
    
    printf("结构体占用的sizeof\t%lu\n",sizeof(struct score));
    struct score scores2[5];
    printf("--------------------------------------------------\n");
    float scores3[10] = {32,34,45,45,66,45,67,89,93,68};
    int pointer1[101] = {-1};
    for (int index = 0; index <10; index ++) {
       int a = scores3[index];
        pointer1[a] = index;
    }
    int guade;
    while (1) {
        scanf("%d",&guade);
        if (pointer1[guade]!= -1) {
            printf("学生的学号%d\n",pointer1[guade]);
        }else{
            printf("没有此学生");
        }
    }
    return 0;
}
