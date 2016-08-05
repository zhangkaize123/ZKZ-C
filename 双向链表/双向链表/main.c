//
//  main.c
//  双向链表
//
//  Created by 张凯泽 on 16/6/13.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void llist_op(const void *);
struct student{
    int ID;
    char name[20];
    float matchScore;
    
};
typedef struct student Score;
typedef Score * ScoreData;
//链表节点
struct llink_list{
    struct student * data;
    struct llink_list * pre;
    struct llink_list * next;
};
typedef struct llink_list Note;
typedef Note * LLink;
//链表头节点
struct llink_head{
    struct llink_list llink;
    int size;// 各节点数据大小
};
typedef struct llink_head Note_Head;
typedef Note_Head * LLink_head;
//创建头节点
LLink_head CreateLLink_head(int size)
{
    LLink_head llink_head = (LLink_head)malloc(sizeof(Note_Head));
    if (llink_head == NULL) {
        printf("创建头节点失败\n");
        return NULL;
    }
    llink_head ->llink.pre = &(llink_head ->llink);//前区指向头节点中的链表地址
    llink_head ->llink.next = &(llink_head ->llink);//后记指向头节点的链表地址
    llink_head ->llink.data = NULL;//头节点中链表的数据设置为NULL
    llink_head ->size = size;
    
    return llink_head;
}
int InsertLLink(LLink_head head,int model,ScoreData data)
{
    LLink llink = (LLink)malloc(sizeof(Note));
    if (llink == NULL) {
        printf("创建节点失败\n");
        return -1;
    }
    //创建节点数据
    llink ->data = (ScoreData)malloc(sizeof(Note));
    if (llink ->data == NULL) {
         printf("创建节点数据结构体失败\n");
        return -1;
       
    }
    memcpy(llink ->data,data ,head ->size);
    if (model == 1) {//中间插入
        llink ->pre = &head ->llink;
        llink ->next = head ->llink.next;
        
    }else if (model == 2)//链表最后节点插入
    {
        llink ->next = &head ->llink;
        llink ->pre = head ->llink.pre;
    }
    llink ->pre ->next = llink;
    llink ->next ->pre = llink;
    // printf("%s\n",llink ->data ->name);
    return 0;
}
void print_s(const void * data)
{
    const struct student * studentData = data;
    //printf("%s--->%s---->%f---->%d\n",studentData ->name,studentData ->sex,studentData ->score,studentData ->studentID);
    printf("%d\n",studentData ->ID);
    printf("%f\n",studentData ->matchScore);
    printf("%s\n",studentData ->name);
    //printf("%s\n",studentData ->sex);
    printf("-------------------------------\n");
}
// 展示
void showLlink_list(LLink_head head,llist_op *op)
{
    if (head == NULL) {
        return ;
    }
    LLink p;
    for (p = head ->llink.next; p != &head->llink; p = p->next) {
        op(p ->data);
    }
    
}

int main(int argc, const char * argv[]) {

    printf("-----%lu\n",sizeof(Score));
    LLink_head head = CreateLLink_head(28);
    ScoreData scoredata;
     scoredata = (ScoreData)malloc(sizeof(Score));
    scoredata ->ID = 12;
    strcpy(scoredata ->name,"ios_1");
    scoredata ->matchScore = 99.8;
    InsertLLink(head, 1, scoredata);
     scoredata = (ScoreData)malloc(sizeof(Score));
    scoredata ->ID = 13;
    strcpy(scoredata ->name,"ios_2");
    scoredata ->matchScore = 199.8;
    InsertLLink(head, 2, scoredata);
    scoredata = (ScoreData)malloc(sizeof(Score));
    scoredata ->ID = 14;
    strcpy(scoredata ->name,"ios_3");
    scoredata ->matchScore = 299.8;
    InsertLLink(head, 1, scoredata);
    showLlink_list(head, print_s);
//    char name[] = "ios";
//    char name1[10]= "\0";
//    memcpy(name1, name, 3);
//    printf("%s\n",name1);
//    ScoreData scoredata = (ScoreData)malloc(sizeof(Score));
//    scoredata ->ID = 12;
//    strcpy(scoredata ->name,"ios_1");
//    scoredata ->matchScore = 99.8;
//    ScoreData scoredata1 = (ScoreData)malloc(sizeof(Score));
//    // ScoreData scoredata1 = NULL;//如果设置scoredata1 设置为NULL时 使用memcpy函数报错
//    memcpy(scoredata1, scoredata, 40);
//    printf("%d,%s,%f\n",scoredata1 ->ID,scoredata1 ->name,scoredata1 ->matchScore);
    return 0;
}
