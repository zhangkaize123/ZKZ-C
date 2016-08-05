//
//  main.m
//  结构体
//
//  Created by 张凯泽 on 16/6/3.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#import <Foundation/Foundation.h>
struct score {
    float Match;
    float English;
    float Chinese;
}s3,s4;
//定义结构体的方法
struct score s,s2;
//取别名
typedef struct score note;
int main(int argc, const char * argv[]) {
    
    s3.English = 45;
    
    s.English = 56;
    note n;
    n.English = 67;
    
    
    
    struct student{
        char Id;
        int Match;
        int English;
        int Chinese;
        double Computer;
        struct student * next;
    };
    struct student s;
    //结构体的 sizeof 为它成员里边最大sizeof 的倍数
    //结构体的地址为他里边第一个元素的地址
    printf("结构体的sizeof%lu\n",sizeof(struct student));
    printf("结构体的地址:%p\n",&s);//0x7fff5fbff818
    printf("结构体第一个元素的地址:%p\n",&s.Id);//0x7fff5fbff818
    printf("结构体第一个元素的地址:%p\n",&s.Id+1);
    printf("结构体第二个元素的地址:%p\n",&s.Match);//0x7fff5fbff81c
    printf("结构体第三个元素的地址:%p\n",&s.English);//0x7fff5fbff820
    printf("结构体第四个元素的地址:%p\n",&s.Chinese);//0x7fff5fbff824
    printf("结构体第五个元素的地址:%p\n",&s.Computer);//0x7fff5fbff828
    
    printf("-------------------------------------------\n");
    struct student first,second;
    first.Id = 'A';
    first.Match = 34;
    first .English = 45;
    first .Chinese = 56;
    first.Computer = 67;
    first.next = NULL;
    
    second.Id = 'B';
    second.English = 78;
    second.Match = 90;
    second.Computer = 99;
    second.Chinese = 45;
    second.next = NULL;
    first.next = &second;
    struct student * begin = &first;
    while (begin != NULL) {
        printf("学号:%c\t英语成绩:%d\t数学成绩:%d\t语文成绩:%d\t计算机成绩:%f\n",begin ->Id,begin ->English,begin ->Match,begin ->Chinese,begin ->Computer);
        begin = begin ->next;
    }
    return 0;
}
