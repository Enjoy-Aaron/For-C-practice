#include <iostream>
#include <cstdio>
#define OK 1
using namespace std;

typedef int Status;
typedef struct QNode {
    int data;
    struct QNode *next;
}QNode;
typedef struct {
    QNode *head;
    QNode *tail;
}LinkQueue;

Status InitQueue(LinkQueue &Q)
{
    Q.head = new QNode;
    Q.tail = Q.head;
    return OK;
}

Status Push(LinkQueue &Q, int e)
{
    QNode *p = new QNode;
    p->data = e;
    Q.tail->next = p;
    Q.tail = p;
    return OK;
}

int main()
{
    int n,m;
    LinkQueue Q1,Q2;
    InitQueue(Q1);InitQueue(Q2);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) {
        Push(Q1,i);
    }
    Q1.tail->next = Q1.head->next;
    for (int i=1;i<=m;++i) {
        Push(Q2,i);
    }
    Q2.tail->next = Q2.head->next;
    int k;
    scanf("%d",&k);
    QNode *p1 = Q1.head->next;
    QNode *p2 = Q2.head->next;
    for (int i=1;i<k;++i) {
        p1 = p1->next;
        p2 = p2->next;
    }
    printf("%d %d\n",p1->data,p2->data);
    return 0;
}
