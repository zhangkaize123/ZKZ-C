//
//  ViewController.m
//  Llink_list_Demo
//
//  Created by 张凯泽 on 16/5/11.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#import "ViewController.h"
typedef void llist_op(const void *);
typedef void (* mylog)(const void*);
typedef int compareLlink_list(void *,const void * );
struct student{
    int studentID;
    char name[10];
    double score;
    //char * sex;
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
};

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
int inserLlink_list(struct llink_head_list * head , void * data,int model)
{
    if (head == NULL) {
        return -1;
    }
    struct Llink_list * note = (struct Llink_list*)malloc(sizeof(* note));//创建一个节点
    if (note == NULL) {
        return -2;
    }
    note ->data = (struct student *)malloc(sizeof(struct student));
    if (note ->data == NULL) {
        return -3;
    }
#pragma mark----zkz---如果使用memcpy(data, note ->data, head ->size);在打印的时候会报错
    //memcpy(<#void *#>, <#const void *#>, <#size_t#>)
    memcpy(note ->data,data , head ->size);
    //memcpy(data, note ->data, head ->size);
    //note ->data = data;
    if (model == 1) {//在头节点的尾部添加
        //因为 head ->llink_list 是获得值，具体查看head结构体细节
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
   // NSLog(@"%s--->%s---->%f---->%d",studentData ->name,studentData ->sex,studentData ->score,studentData ->studentID);
//    NSLog(@"%d----%s",studentData ->studentID,studentData ->name);
    NSLog(@"%d----",studentData ->studentID);
}

// 展示
void showLlink_list(struct llink_head_list* head,llist_op *op)
{
    if (head == NULL) {
        return ;
    }
    struct Llink_list * p;
    for (p = head ->llink_list.pnext; p != &head ->llink_list; p = p->pnext) {
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
static int compareStudentIDAndLogMessage(void * llink,const void * key)
{
    struct Llink_list * llinkCur = llink;
    struct student * studentIdent = llinkCur ->data;
    int * a = (int *)key;
    
    return (studentIdent ->studentID - *a);
}
//比较姓名设定名字都不相同
static int compareNameAndLogMessage(void *llink,const void * key)
{
    struct Llink_list * llinkCur = llink;
    struct student * studentIdent = llinkCur ->data;
    int a = strcmp(studentIdent ->name, key);
  //int a = 0;
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
//

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    int res;
    //创建头节点
    struct llink_head_list * head = creat_llink_list(40);
    if (head == NULL) {
        return;
    }
    struct student * const student1 = (struct student*)malloc(sizeof(struct student));
    student1 ->studentID = 1;
    student1 ->score = 61.0;
    //student1 ->sex = "man";
    student1 ->name = "ios1";
    
    //struct Llink_list * llink_list1 = (struct Llink_list*)malloc(sizeof(struct Llink_list*));
    //llink_list1 ->data = student1;
    //memcpy(llink_list1 ->data, student1, head ->size);

   res =inserLlink_list(head, student1, 2);
    if (res) {
        NSLog(@"插入失败1");
        return;
    }
    
    struct student * student2 = (struct student*)malloc(sizeof(struct student));
    student2 ->studentID = 2;
    student2 ->score = 62.0;
    //student2 ->sex = "man";
    student2 ->name = "ios2";
    //struct Llink_list * llink_list2 = (struct Llink_list*)malloc(sizeof(struct Llink_list*));
//    llink_list2 ->data = student2;
//    inserLlink_list(head,llink_list2, student2);
   res= inserLlink_list(head, student2, 1);
    if (res) {
        NSLog(@"插入失败2");
        return;
    }
    struct student * student3 = (struct student*)malloc(sizeof(struct student));
    student3 ->studentID = 3;
    student3 ->score = 63.0;
    //student3 ->sex = "man";
    student3 ->name = "ios3";
//    struct Llink_list * llink_list3 = (struct Llink_list*)malloc(sizeof(struct Llink_list*));
//    llink_list3 ->data = student3;
//    inserLlink_list(head,llink_list3, student3);
   res= inserLlink_list(head, student3, 2);
    if (res) {
        NSLog(@"插入失败3");
        return;
    }
    struct student * student4 = (struct student*)malloc(sizeof(struct student));
    student4 ->studentID = 4;
    student4 ->score = 64.0;
    //student4 ->sex = "man";
    student4 ->name = "ios4";
//    struct Llink_list * llink_list4 = (struct Llink_list*)malloc(sizeof(struct Llink_list*));
//    llink_list4 ->data = student4;
//    inserLlink_list(head,llink_list4, student4);
    res=inserLlink_list(head, student4, 1);
    if (res) {
        NSLog(@"插入失败4");
        return;
    }
    //销毁链表
    //destroyLlink_List(head);
    //展示
    //showLlink_list(head, print_s);
    logLlink_list(head,print_s);
    struct student * score;
    score = findLlink_list(head, "ios2",compareNameAndLogMessage);
    if (score == NULL) {
        NSLog(@"未找到");
    }else {
        print_s(score);
    }
    int aa = 2;
    score = findLlink_list(head, &aa, compareStudentIDAndLogMessage);
    if (score == NULL) {
        NSLog(@"未找到");
    }else {
        print_s(score);
    }
   int aaa = deleteLlink_list(head, &aa, compareStudentIDAndLogMessage);
    NSLog(@"*******%d",aaa);
    showLlink_list(head, print_s);
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

@end
