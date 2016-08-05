//
//  main.c
//  使用结构体创建二叉树
//
//  Created by 张凯泽 on 16/6/19.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
struct Btree{
    int data;
    int left;
    int right;
};
struct Btree btree [15];
void CreateBtree(int * arr,int len)
{
    int level;//树的层级
    int pos;
    btree[0].data = arr[0];
    for (int i = 1 ; i <len; i++) {
        level = 0;
        pos = 0;
        btree[i].data = arr[i];
        while (pos == 0) {
            if (arr[i]>btree[level].data) {//右节点
                if (btree[level].right != -1) {
                    level = btree[level].right;
                }else{
                    pos = -1;
                }
                
            }else{//左
                if (btree[level].left != -1) {
                    level = btree[level].left;
                }else{
                    pos = 1;
                }
            }
            if (pos == 1) {
                
            }else{
                btree[level].right = i;
            }
        }
        
    }
}
int main(int argc, const char * argv[]) {
    
    int data[10] = {5,6,4,8,2,3,7,1,9};
    for (int i = 0; i<15; i++) {
        btree[i].data= 0;
        btree[i].right = -1;
        btree[i].left = -1;
    }
    CreateBtree(data, 9);
    return 0;
}
