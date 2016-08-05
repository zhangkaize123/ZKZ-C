//
//  main.c
//  二叉树
//
//  Created by 张凯泽 on 16/6/19.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void createbtree(int *btree,int *data ,int len)
{
    int level;
    int i;
    btree[1] = data[1];
    for (i = 2; i<len; i++) {
        level = 1;
        while (btree[level] != 0) {
            if (btree[level]<data[i]) {//右节点
               level= 2*level+1;
                printf("右:%d\n",level);
            }else{//左节点
                level = 2*level;
                printf("左:%d",level);
            }
        }
        btree[level] = data[i];
    }
}

int main(int argc, const char * argv[]) {
    
    int btree[16] = {0};
    int data[10] = {0,5,6,4,8,2,3,7,1,9};
    createbtree(btree,data,9);
    for (int i = 0; i<16; i++) {
        printf("%d,[%d]\n",btree[i],i);
    }
    printf("动态数组\n");
    int * a = malloc(sizeof(int)*5);
    for (int j = 0; j <5; j++) {
        printf("%p\n",a+j);
    }
    
    return 0;
}
