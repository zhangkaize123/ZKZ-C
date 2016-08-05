//
//  main.c
//  二维数组
//
//  Created by 张凯泽 on 16/6/3.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    
    
    //int[行数][列数]
    int class[6][5]= {0,1,2,3,4,
                      5,6,7,8,9,
                      3,4,5,6,7,
                      2,1,0,4,5,
                      4,4,6,7,3,
                      3,4,2,1,0};
    int sum = 0;
    for (int i = 0; i<6; i++) {
        for (int j = 0; j<5; j++) {
            //printf("--------%d\n",class[i][j]);
            sum= sum + class[i][j];
        }
    }
    printf("sum = %d\n",sum);
    printf("class = %p\n",class);
    for (int i = 0; i <6; i++) {
        printf("---%p\n",class[i]);
        for (int j= 0; j<5; j++) {
            printf("%p\n",&class[i][j]);
        }
    }
    //映射成一维数组
    int class1[30]={0,1,2,3,4,
        5,6,7,8,9,
        3,4,5,6,7,
        2,1,0,4,5,
        4,4,6,7,3,
        3,4,2,1,0};
    
    
    printf("二维数组数值:%d\n",class[2][3]);//6
    printf("映射的一维数组值:%d\n",class1[2*5+3]);//以列为主的映射 行数*总列数+列数
    printf("-----------------------------------------------------\n");
    
            return 0;
}
