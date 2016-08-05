//
//  main.c
//  使用递归走迷宫问题
//
//  Created by 张凯泽 on 16/6/18.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
int maze[7][10] = {
    1,1,1,1,1,1,1,1,1,1,
    1,0,1,0,1,0,0,0,0,1,
    1,0,1,0,1,0,1,1,0,1,
    1,0,1,0,1,1,1,0,0,1,
    1,0,1,0,0,0,0,0,1,1,
    1,0,0,0,1,1,1,0,0,1,//入口（5，8）
    1,1,1,1,1,1,1,1,1,1
};
int find_path(int x,int y)
{
    if (x == 1&&y == 1) {
        maze[1][1] = 2;
        return 1;
    }else{
        if (maze[x][y] == 0) {
            maze[x][y]= 2;
            if (find_path(x-1,y)+find_path(x+1,y)+find_path(x,y-1)+find_path(x,y+1)>0) {
                return 1;
            }else{
                maze[x][y] = 0;
                return 0;
            }
        }else{
            return 0;
        }
    }
    
}
int find_path1(int x,int y)
{
    if (x == 1 && y == 1) {
        maze[x][y] = 2;
        return 1;
    }else{
        if (maze[x][y] == 0) {
            maze[x][y] = 2;
        }else{
            
        }
        
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int i,j;
    //printf("%d\n",maze[4][8]);
    find_path(5, 8);
    printf("迷宫走势\n");
    for (i =0; i<7; i++) {
        for (j = 0; j<10; j++) {
            printf("%d\t",maze[i][j]);
            
        }
        printf("\n");
    }

    return 0;
}
