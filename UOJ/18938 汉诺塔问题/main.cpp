#include <iostream>
#include <cstdio>
#define OK 1
#define ERROR 0
using namespace std;
typedef int Status;
typedef struct {
    char from;
    int num;
    char to;
}SElemType;
typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;
LinkStack S;

Status InitStack(LinkStack S)
{
    S = NULL;
    return OK;
}

Status Push(LinkStack &S, SElemType e)
{
    LinkStack p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

Status Pop(LinkStack &S, SElemType &e)
{
    if (S == NULL) return ERROR;
    e = S->data;
    LinkStack p = S;
    S = S->next;
    delete p;
    return OK;
}

Status StackEmpty(LinkStack S)
{
    if (S == NULL) return true;
    return false;
}

SElemType GetTop(LinkStack S)
{
    if (S == NULL)
        return S->data;
}

void Han(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("%c->%d->%c\n",from,n,to);
        return;
    }
    Han(n-1, from, aux, to);
    printf("%c->%d->%c\n",from,n,to);
    Han(n-1, aux, to, from);
    return;
}

int main()
{
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    InitStack(S);
    Han(n,a,b,c);
    return 0;
}
