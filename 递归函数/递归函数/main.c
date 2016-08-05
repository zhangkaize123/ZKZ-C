//
//  main.c
//  递归函数
//
//  Created by 张凯泽 on 16/6/14.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
int list[] = {1,2,3,4,5,6};
void invert_array(int j)
{
    if (j<6) {
        invert_array(j+1);
        printf("%d\n",list[j]);
    }
}
int factorial(int j)
{
    int sum;
    if (j == 0) {
        sum = 1;
    }else{
        sum = j * factorial(j -1);
    }
    return sum;
}
//X的N次方写递归函数
int multip(int X,int n,int pos)
{
    int mul;
    if (n == pos) {
        mul = 1;
    }else{
        mul = X * multip(X, n, pos+1);
    }
    return mul;
}
int main(int argc, const char * argv[]) {
//    for (int i = 0; i<6; i++) {
//        printf("%d\n",list[i]);
//        printf("\n");
//        printf("递归输出数据内容\n");
//        invert_array(0);
//        printf("\n");
//    }
//    printf("*****************************************\n");
//    printf("%d\n",factorial(3));
    printf("%d\n",multip(3, 4, 0));
    return 0;
}
