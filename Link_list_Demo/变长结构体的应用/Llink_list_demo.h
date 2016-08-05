//
//  Llink_list_demo.h
//  Link_list_Demo
//
//  Created by 张凯泽 on 16/5/16.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#ifndef Llink_list_demo_h
#define Llink_list_demo_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student{
    int studentID;
    char  name[10];
    int score;
    char sex[5];
};
//双向链表节点
struct Llink_list{
    void * data;
    struct Llink_list * pre;//前区
    struct Llink_list * pnext;//后继
    
};
//链表的头节点
struct llink_head_list{
    struct Llink_list llink_list;//链表
    int size;//data的大小
    int (* inser_link)(struct llink_head_list *, void * ,int );
};

typedef void llist_op(const void *);
typedef void (* mylog)(const void*);
typedef int compareLlink_list(void *,const void * );
//创建头节点
struct llink_head_list * creat_llink_list(int initsize);
//销毁链表
void destroyLlink_List(struct llink_head_list * head_link);
//插入数据
int inserLlink_list(struct llink_head_list * head , void * data,int model);
void print_s(const void * data);
// 展示
void showLlink_list(struct llink_head_list* head,llist_op *op);
 int compareNameAndLogMessage(void *llink,const void * key);
 int compareStudentIDAndLogMessage(void * llink,const void * key);
//查找
void * findLlink_list(struct llink_head_list * head,const void * key,compareLlink_list * comp);
//删除
int deleteLlink_list(struct llink_head_list * head,const void * key,compareLlink_list * comp);

#endif /* Llink_list_demo_h */
