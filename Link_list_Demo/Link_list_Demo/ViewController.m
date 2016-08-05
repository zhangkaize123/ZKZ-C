//
//  ViewController.m
//  Link_list_Demo
//
//  Created by 张凯泽 on 16/5/10.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#import "ViewController.h"
struct Link_list{
    int data;
    struct Link_list * Pnext;
};
struct Link_list * head_list;
//创建链表 head节点
bool creatLink_list()
{
    head_list = (struct Link_list*)malloc(sizeof(struct Link_list));
    if (head_list == NULL) {
        return false;
    }else{
        head_list ->data = 0;
        head_list ->Pnext = NULL;
        return true;
    }
    
    
}
//增加节点从尾部添加
bool addLink_list(struct Link_list * note)
{
    //没有头节点
    if (head_list == NULL) {
        return false;
    }
    //只有头节点
    if (head_list ->Pnext == NULL) {
        head_list->Pnext = note;
        note ->Pnext = NULL;
        return true;
    }
    //有两个节点
    struct Link_list * p = head_list ->Pnext;
    struct Link_list * temp = head_list;
    while (p != NULL) {
        temp = p;
        p = p ->Pnext;

    }
    temp->Pnext  = note;
    note ->Pnext = NULL;
    
    return true;

}
//插入
bool insertLink_list(struct Link_list * note)
{
    if (head_list == NULL) {
        return false;
    }
    struct Link_list * p = head_list;
    
    note->Pnext = p->Pnext;
    p -> Pnext = note;
        return true;
    
}

//删除
bool deleteLink_list(int index)
{
    if (head_list == NULL) {
        return false;
    }
    struct Link_list * p = head_list ->Pnext;
    int lenth = 0;
    while (p != NULL) {
        lenth ++;
        p = p->Pnext;
        
    }
    if (lenth<index) {
        return false;
    }else{
    struct Link_list * q = head_list;
        p = head_list;
        for (int i = 0; i <index; i++) {
            q = p;
            p = p ->Pnext;
            
        }
        
        q ->Pnext = p ->Pnext;
        free(p);
        return true;
    
    }
    
}
//销毁链表
void destroyNodeList()
{
    //没有头节点
    if (head_list == NULL) {
        return;
    }
    //只有头节点
    if (head_list ->Pnext == NULL) {
        free(head_list);
        return;
    }
    //两个节点以上者（包括两个节点）
    struct Link_list * p = head_list->Pnext;
    // = NULL;
    while (p != NULL) {
        struct Link_list * q = p;
        p = p->Pnext;
        free(q);
    }
    free(head_list);
    head_list = NULL;
}
// 展示
void showLink_list()
{
    if (head_list == NULL) {
        return ;
        
    }
    struct Link_list * p = head_list;
    while (p != NULL) {
        NSLog(@"%p-----%d",p,p ->data);
       p = p ->Pnext;
        
    }
    
}
//逆序排列
void reverseNodeList()
{
    if(NULL == head_list)
    {
        return;
    }
    //如果链表长度为1
    if(head_list->Pnext == NULL)
    {
        return;
    }
    struct Link_list* p = head_list->Pnext;
    struct Link_list* q = p->Pnext;
    struct Link_list* t = NULL;
    while(NULL != q)
    {
        t = q->Pnext;
        q->Pnext = p;
        p = q;
        q = t;
    }
    head_list->Pnext->Pnext = NULL;
    head_list->Pnext = p;
}
//排序(降序)
void sort()
{
    //冒泡排序
    struct Link_list* pHead = head_list;
    if(head_list == NULL)
    {
        return;
    }
    if(pHead->Pnext == NULL)
    {
        return;
    }
    struct Link_list* pi = pHead->Pnext;
    struct Link_list* pj = pi->Pnext;
    for(;pi != NULL;pi=pi->Pnext)
    {
        for(pj = pi->Pnext;pj != NULL;pj=pj->Pnext)
        {
            if(pj->data>pi->data)
            {
                int tmp = pj->data;
                pj->data = pi->data;
                pi->data = tmp;
            }
        }
    }
}
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    creatLink_list();
    
    struct Link_list * note1 = (struct Link_list*)malloc(sizeof(struct Link_list));
    note1 ->data = 1;
    addLink_list(note1);
    
    struct Link_list * note2 = (struct Link_list*)malloc(sizeof(struct Link_list));
    note2 ->data = 2;
    addLink_list(note2);
    
    struct Link_list * note3 = (struct Link_list*)malloc(sizeof(struct Link_list));
    note3 ->data = 3;
    addLink_list(note3);
    
    struct Link_list * note4 = (struct Link_list*)malloc(sizeof(struct Link_list));
    note4 ->data = 4;
    addLink_list(note4);
    
    //showLink_list();
    //destroyNodeList();
    //deleteLink_list(2);
    showLink_list();
    reverseNodeList();
    NSLog(@"-------------------------");
    showLink_list();
     NSLog(@"-------------------------");
    sort();
    showLink_list();
    
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
