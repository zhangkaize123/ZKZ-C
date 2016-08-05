//
//  main.m
//  使用结构体创建二叉树2
//
//  Created by 张凯泽 on 16/7/1.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#import <Foundation/Foundation.h>
struct tree{
    int data;
    struct tree * left;
    struct tree * right;
};
typedef struct tree treeNote;
typedef treeNote * btree;
btree insertnote(btree root ,int value)
{
    btree newnote;//树根指针
    btree current;//当前树节点指针
    btree back = NULL;//父节点指针
    //创建新节点内存
    newnote = (btree)malloc(sizeof(treeNote));
    newnote ->data = value;
    newnote ->left = NULL;
    newnote ->right = NULL;
    if (root == NULL) {
        return newnote;
    }else{
        current = root;
        while (current != NULL) {
            back = current;
            if (current ->data >value) {
                current = current ->left;
            }else{
                current = current ->right;
            }
        }
        if (back ->data >value) {
            back ->left = newnote;
        }else{
            back ->right = newnote;
        }
    }
    
    return root;
}
btree creatbtree(int * data ,int len)
{
    btree root = NULL;
    int i;
    for (i = 0; i<len; i++) {
        root = insertnote(root, data[i]);
    }
    return root;
}
int main(int argc, const char * argv[]) {

    btree root = NULL;
    int data[9] = {5,6,4,8,2,3,7,1,9};
    root = creatbtree(data, 9);
    return 0;
}
