#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#define OK 1
#define ERROR 0
using namespace std;
typedef struct Operator {
    char oper;
    int locator;
} Operator,SElemType,QElemType;
typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;
typedef int Status;

Status InitStack(LinkStack &S)
{
    S = NULL;
    return OK;
}

Status StackEmpty(LinkStack S)
{
    if (S == NULL) return 1;
    return 0;
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

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode;

typedef struct {
    QNode *front;
    QNode *rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q)
{
    Q.front = new QNode;
    Q.front->next = NULL;
    Q.rear = Q.front;
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear) return 1;
    return 0;
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
    QNode *p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear )return ERROR;
    QNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    delete p;
    return OK;
}

int main()
{
    LinkStack S;
    LinkQueue err;
    InitStack(S);
    InitQueue(err);
    int is_err[1001]={};
    string s;
    while (cin >> s) {
        for (int i=0;i<s.length();++i) {
            if (s[i] == '(') {
                SElemType e;
                e.locator = i; e.oper = s[i];
                Push(S,e);
            }
            if (s[i] == ')') {
                if (StackEmpty(S)) {
                    Operator tmp;
                    tmp.oper = s[i];
                    tmp.locator = i;
                    EnQueue(err,tmp);
                }
                else {
                    SElemType x;
                    Pop(S,x);
                }
            }
        }
        while (!StackEmpty(S)) {
            Operator tmp;
            Pop(S,tmp);
            EnQueue(err,tmp);
        }
        while (!QueueEmpty(err)) {
            QElemType tmp;
            DeQueue(err,tmp);
            is_err[tmp.locator] = tmp.oper=='('? 1:2;
        }
        cout << s << endl;
        for (int i=0;i<s.length();++i) {
            if (!is_err[i]) {
                printf(" ");
                continue;
            }
            if (is_err[i] == 1) printf("$");
            else printf("?");
            is_err[i] = 0;
        }
        printf("\n");
    }
    return 0;
}
