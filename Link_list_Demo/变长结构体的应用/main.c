//
//  main.c
//  变长结构体的应用
//
//  Created by 张凯泽 on 16/5/16.
//  Copyright © 2016年 rytong_zkz. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Llink_list_demo.h"
int main(int argc, const char * argv[]) {
    int res;
    //创建头节点
    struct llink_head_list * head = creat_llink_list(40);
    if (head == NULL) {
        return 0;
    }
    struct student tep1;
    tep1.studentID =1;
    strcpy(tep1.name, "ios1");
    strcpy(tep1.sex, "man");
    tep1.score = 99;
    //inserLlink_list(head, &tep1, 1);
    head ->inser_link(head, &tep1, 1);
    printf("1111111\n");
    //showLlink_list(head, print_s);
    struct student tep2;
    tep2.studentID =2;
    strcpy(tep2.name, "ios2");
    strcpy(tep2.sex, "man");
    tep2.score = 98;
    inserLlink_list(head, &tep2, 1);
    printf("2222222\n");
    struct student tep3;
    tep3.studentID =3;
    strcpy(tep3.name, "ios3");
    strcpy(tep3.sex, "man");
    tep3.score = 97;
    inserLlink_list(head, &tep3, 1);
    printf("3333333\n");
    struct student tep4;
    tep4.studentID =4;
    strcpy(tep4.name, "ios4");
    strcpy(tep4.sex, "man");
    tep4.score = 96;
    inserLlink_list(head, &tep4, 1);
    printf("44444444\n");
    showLlink_list(head, print_s);
//    //for (int i = 0; i<4; i++) {
//        tep.studentID = i;
//        //strcpy(tep.sex, "man");
//        snprintf(tep.sex, 5, "sex%d",i);
//       // strcpy(tep.name, "ios");
//        snprintf(tep.name, 10, "stu%d",i);
//        tep.score = 65.0+i;
//        res = inserLlink_list(head, &tep, 1);
//        printf("*****%d\n",i);
//        if (res != 0) {
//            break;
//        }
//    }
    //销毁链表
    //destroyLlink_List(head);
    //展示
   // showLlink_list(head, print_s);
//    printf("-----------------------------------\n");
//    //logLlink_list(head,print_s);
//    struct student * score;
////    score = findLlink_list(head, "ios2",compareNameAndLogMessage);
////    if (score == NULL) {
////        printf("未找到\n");
////    }else {
////        print_s(score);
////    }
//    int aa = 2;
//    score = findLlink_list(head, &aa, compareStudentIDAndLogMessage);
//    if (score == NULL) {
//        printf("未找到\n");
//    }else {
//        print_s(score);
//    }
//    int aaa = deleteLlink_list(head, &aa, compareStudentIDAndLogMessage);
//    printf("*******%d\n",aaa);
//    showLlink_list(head, print_s);

    return 0;
}
