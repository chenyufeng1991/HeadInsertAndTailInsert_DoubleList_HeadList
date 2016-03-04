//
//  main.c
//  HeadInsertAndTailInsert_DoubleList_HeadList
//
//  Created by chenyufeng on 16/3/4.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//


/**
 *  分别使用头插法和尾插法来构建带头节点和尾结点的双向非循环链表
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//初始化带头结点和尾结点的非循环双向链表
void InitialList(Node **pHead,Node **pTail){

    *pHead = (Node *)malloc(sizeof(Node));
    *pTail = (Node *)malloc(sizeof(Node));

    if (*pHead == NULL || *pTail == NULL) {
        printf("%s函数执行，内存分配失败，初始化双链表失败\n",__FUNCTION__);
    }else{
        //这个里面是关键，也是判空的重要条件
        (*pHead)->prior = NULL;
        (*pTail)->next = NULL;

        //链表为空的时候把头结点和尾结点连起来
        (*pHead)->next = *pTail;
        (*pTail)->prior = *pHead;

        printf("%s函数执行，带头结点和尾节点的双向非循环链表初始化成功\n",__FUNCTION__);
    }
}

//创建带头结点和尾结点的双向非循环链表(头插法)
void HeadInsertCreateList(Node *pHead,Node *pTail){

    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    while (pInsert->element > 0) {

        pHead->next->prior = pInsert;
        pInsert->next = pHead->next;
        pInsert->prior = pHead;
        pHead->next = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->prior = NULL;
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行完成，头插法建立带头节点和尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}

//创建带头结点和尾结点的双向非循环链表(尾插法)
void TailInsertCreateList(Node *pHead,Node *pTail){

    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    while (pInsert->element > 0) {

        pTail->prior->next = pInsert;
        pInsert->prior = pTail->prior;
        pInsert->next = pTail;
        pTail->prior = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->prior = NULL;
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行完成，尾插法建立带头节点和尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}

//正序打印链表
void PrintList(Node *pHead,Node *pTail){

    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        printf("%d ",pMove->element);
        pMove = pMove->next;
    }

    printf("\n%s函数执行，正序打印带头结点尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}


int main(int argc, const char * argv[]) {

    Node *pHead;//头结点
    Node *pTail;//尾结点

    InitialList(&pHead, &pTail);

    HeadInsertCreateList(pHead, pTail);
    PrintList(pHead, pTail);
    TailInsertCreateList(pHead, pTail);
    PrintList(pHead, pTail);


    return 0;
}























