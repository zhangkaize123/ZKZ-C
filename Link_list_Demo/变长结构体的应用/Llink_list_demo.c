//
//  Llink_list_demo.c
//  Link_list_Demo
//
//  Created by 张凯泽 on 16/5/16.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include "Llink_list_demo.h"


//创建头节点
struct llink_head_list * creat_llink_list(int initsize)
{
    //在结构体中 如果一个结构体的指针方法它里边的数据使用"->",如果是单纯的结构体访问它里边的数据使用"."进行访问。
    struct llink_head_list * head_list = (struct llink_head_list *)malloc(sizeof(struct llink_head_list));
    
    if (head_list == NULL) {
        return NULL;
    }
    head_list->size = initsize;
    head_list ->llink_list .data = NULL;
    head_list ->llink_list .pre = &head_list ->llink_list;
    
    head_list ->llink_list .pnext = &head_list ->llink_list;
    head_list ->inser_link = inserLlink_list;
    return head_list;
}
//销毁链表
void destroyLlink_List(struct llink_head_list * head_link)
{
    struct Llink_list * link_list ,*next;
    for (link_list=head_link ->llink_list.pnext; link_list != &head_link ->llink_list; link_list = next) {
        next = link_list ->pnext;
        free(link_list ->data);
        free(link_list);
    }
    
    free(head_link);
}
//插入数据
int inserLlink_list(struct llink_head_list * head ,  void * data1,int model)
{
    if (head == NULL) {
        return -1;
    }
    struct Llink_list * note;
    /*
     error for object 0x100105568: incorrect checksum for freed object - object was probably modified after being freed.
     *** set a breakpoint in malloc_error_break to debug
     
     */
     note = (struct Llink_list*)malloc(sizeof(struct Llink_list));//创建一个节点
    if (note == NULL) {
        return -2;
    }
    note ->data = (struct student *)malloc(sizeof(struct student));
    if (note ->data == NULL) {
        return -3;
    }
    memcpy(note ->data, data1, head ->size);
    //note ->data = data1;
    if (model == 1) {//在头节点的尾部添加
        note ->pre = &head ->llink_list;
        note ->pnext = head ->llink_list.pnext;
    }else if (model == 2)//在头节点的前面添加
    {
        note ->pnext = &head ->llink_list;
        note ->pre = head ->llink_list.pre;
    }else{
        return -4;
        
    }
    note ->pnext ->pre = note;
    note ->pre ->pnext = note;
    return  0;
}
//展示的回调方法
void print_s(const void * data)
{
    const struct student * studentData = data;
     //printf("%s--->%s---->%f---->%d\n",studentData ->name,studentData ->sex,studentData ->score,studentData ->studentID);
    printf("%d\n",studentData ->studentID);
    printf("%d\n",studentData ->score);
    printf("%s\n",studentData ->name);
    printf("%s\n",studentData ->sex);
    printf("-------------------------------\n");
        //printf("%d----%s",studentData ->studentID,studentData ->name);
    //printf("%d----",studentData ->studentID);
    //printf("%d \n",studentData ->studentID);
}

// 展示
void showLlink_list(struct llink_head_list* head,llist_op *op)
{
    if (head == NULL) {
        return ;
    }
    struct Llink_list * p;
    struct student * sss;
    for (p = head ->llink_list.pnext; p != &head ->llink_list; p = p->pnext) {
        sss = p ->data;
        //printf("%d\n",sss ->studentID);
        //printf("%d\n",sss ->score);
       // printf("%s\n",sss ->name);
        //printf("%s\n",sss ->sex);
        //printf("-------------------------------\n");
        op(p ->data);
    }
}
void logLlink_list(struct llink_head_list * head,mylog log1)
{
    if (head == NULL) {
        return ;
    }
    struct Llink_list * p;
    for (p = head ->llink_list.pnext; p != &head ->llink_list; p = p->pnext) {
        log1(p ->data);
    }
    
}
//比较学号
 int compareStudentIDAndLogMessage(void * llink,const void * key)
{
    struct Llink_list * llinkCur = llink;
    struct student * studentIdent = llinkCur ->data;
    int * a = (int *)key;
    
    return (studentIdent ->studentID - *a);
}
//比较姓名设定名字都不相同
 int compareNameAndLogMessage(void *llink,const void * key)
{
    struct Llink_list * llinkCur = llink;
    struct student * studentIdent = llinkCur ->data;
    //int a = strcmp(studentIdent ->name, key);
    int a = 0;
    return a;
}
//查找私有函数
static struct Llink_list * findFun(struct llink_head_list *ptr,const void * key,compareLlink_list * com)
{
    struct Llink_list * cur;
    for (cur = ptr ->llink_list.pnext; cur != &ptr ->llink_list; cur = cur ->pnext) {
        
        if (com(cur,key) == 0) {
            
            break;
        }
        
        
        
    }
    
    return cur;
}
//查找
void * findLlink_list(struct llink_head_list * head,const void * key,compareLlink_list * comp)
{
    struct Llink_list * cur;
    cur = findFun(head, key,comp);
    return cur ->data;
    //return  nil;
}

//删除
int deleteLlink_list(struct llink_head_list * head,const void * key,compareLlink_list * comp)
{
    
    struct Llink_list * llink = findFun(head, key, comp);
    if (llink == &head ->llink_list) {
        return -1;
    }
    if (llink != NULL) {//有值才删除
        llink ->pnext ->pre = llink ->pre;
        llink ->pre ->pnext = llink ->pnext;
        free(llink ->data);
        free(llink);
        return 0;
    }else{
        return -2;
    }
}
