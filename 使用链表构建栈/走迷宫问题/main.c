//
//  main.c
//  走迷宫问题
//
//  Created by 张凯泽 on 16/6/17.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct stack_link{
    int x;
    int y;
    struct stack_link * next;
    
};
typedef struct stack_link Stack;
typedef Stack * Stack_note;
Stack_note stack = NULL;
//进栈
Stack_note push(Stack_note *stack1,int *x,int * y)
{
    Stack_note new_stack;
    new_stack = (Stack_note)malloc(sizeof(Stack));
    if (new_stack == NULL) {
        return NULL;
    }
    new_stack ->x = *x;
    new_stack ->y = *y;
    new_stack ->next = *stack1;
    *stack1 = new_stack;
    return *stack1;
}
//出栈
Stack_note pop(Stack_note *stack1,int *x,int *y)
{
    Stack_note top ;
    if (*stack1 != NULL) {
        top = *stack1;
        (*stack1) = (*stack1) ->next;
        *x = (*stack1) ->x;
        *y = (*stack1) ->y;
        free(top);
        return *stack1;
    }else{
        *x = -1;
    }
    
    
    return NULL;
}
/*
 0:可走的路
 1:不可走的路
 2:走过的路
 3:回溯
 优先级是:上,下,左,右
 
 */
int main(int argc, const char * argv[]) {
    int maze[7][10] = {
        1,1,1,1,1,1,1,1,1,1,
        1,0,1,0,1,0,0,0,0,1,
        1,0,1,0,1,0,1,1,0,1,
        1,0,1,0,1,1,1,0,0,1,
        1,0,1,0,0,0,0,0,1,1,//入口（5，8）
        1,0,0,0,1,1,1,0,0,1,
        1,1,1,1,1,1,1,1,1,1
    };
    int i,j;
    int x = 5;//迷宫的入口
    int y = 8;
    while (x != 1 || y != 3)//while语句中的表达式一般是关系表达或逻辑表达式，只要表达式的值为真(非0)即可继续循环。
        /*
         a:  x != 1
         b: y != 3
         a ||b  :a为假b为真 则为假
         */
    {
        
        maze[x][y] = 2;
        if (maze[x-1][y] <= 0) {//上 行减小
            x = x-1;
           stack = push(&stack, &x, &y);
        }else{
            if (maze[x+1][y] <= 0) {//下 行增大
                x = x + 1;
                stack = push(&stack, &x, &y);
                
            }else{
                if (maze[x][y-1]<= 0) {//左 列减小
                    y = y -1;
                    stack = push(&stack, &x, &y);
                }else{
                    if (maze[x][y+1]<= 0) {//右 列增加
                        y = y + 1;
                        stack = push(&stack, &x, &y);
                    }else{//回溯
                        maze[x][y] = 3;
                        stack = pop(&stack, &x, &y);
                        
                        
                    }
                }
            }
        }
        printf("y = %d,x = %d\n",y,x);
    }
    maze[x][y]= 2;
    printf("迷宫走势\n");
    for (i =0; i<7; i++) {
        for (j = 0; j<10; j++) {
            printf("%d\t",maze[i][j]);
            
        }
        printf("\n");
    }
    printf("---------------\n");
    int c = 3,d = 5;
    if (c != 3 || 6 != d) {
        printf("yyyyy\n");
    }
    return 0;
}
