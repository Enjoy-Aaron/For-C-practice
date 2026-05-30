#include <iostream>
#include <cstdio>
#define OK 1
#define ERROR 0
using namespace std;

typedef int SElemType;
typedef int Status;
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;

Status InitStack(LinkStack &S)
{
    S = new StackNode;
    if (!S) return ERROR;
    S = NULL;
    return OK;
}

Status Push(LinkStack &S, SElemType e)
{
    LinkStack p = new StackNode;
    p->data = e;
    p->next =S;
    S = p;
    return OK;
}

Status Pop(LinkStack &S, SElemType &e)
{
    if (!S) return ERROR;
    e = S->data;
    LinkStack p = S;
    S = S->next;
    delete p;
    return OK;
}

Status GetTop(LinkStack S, SElemType &e)
{
    if (S == NULL) return ERROR;
    e = S->data;
    return OK;
}

Status StackTraverse(LinkStack S)
{
    LinkStack p = S;
    while (p) {
        printf("%d",p->data);
        p = p->next;
    }
    return OK;
}

int main()
{
    LinkStack S;
    InitStack(S);
    int n,temp;
    SElemType e;
    scanf("%d",&n);
    while (n) {
        temp = n%8;
        n /= 8;
        Push(S,temp);
    }
    while (S) {
        Pop(S, e);
        printf("%d",e);
    }
    return 0;
}
