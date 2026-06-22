#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstdio>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef struct {
    int arrive;
    int meeting;
} QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef struct
{
   QElemType *base; // 初始化的动态分配存储空间
   int front; // 头指针,若队列不空,指向队列头元素
   int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
 }SqQueue;

Status InitQueue(SqQueue &Q)
{
// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
	Q.base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base) exit(1);
	Q.rear=Q.front=0;
	return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
// 插入元素e为Q的新的队尾元素
	 if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
	 Q.base[Q.rear]=e;
	 Q.rear=(Q.rear+1)%MAXQSIZE;
	 return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
	 if(Q.front==Q.rear) return ERROR;
	 e=Q.base[Q.front];
	 Q.front=(Q.front+1)%MAXQSIZE;
	 return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{
// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
	if(Q.front==Q.rear) return ERROR;
	e=Q.base[Q.front];
	return OK;
}

Status QueueEmpty(SqQueue Q) {
    if (Q.rear == Q.front) return OK;
    return ERROR;
}

int QueueLength(SqQueue Q)
{
// 返回Q的元素个数
	return Q.rear%MAXQSIZE-Q.front%MAXQSIZE;
}

int main() {
    SqQueue Q;
    InitQueue(Q);
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        int arr, ser;
        scanf("%d%d",&arr,&ser);
        QElemType x;
        x.arrive = arr;
        x.meeting = ser;
        EnQueue(Q, x);
    }
    int cur=0, tot=0;
    while (!QueueEmpty(Q)) {
        QElemType e;
        DeQueue(Q, e);
        if (e.arrive >= cur) {
            cur = e.arrive + e.meeting;
        }
        else {
            tot += cur - e.arrive;
            cur = cur + e.meeting;
        }
    }
    double res = 1.0 * tot / n;
    printf("%.2lf\n",res);
    return 0;
}