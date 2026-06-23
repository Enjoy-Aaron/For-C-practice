#include <iostream>
#include <cstdio>
#define OK 1
#define ERROR 0
#define MAXSIZE 1100
using namespace std;

typedef int SElemType;
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

void InitStack(SqStack &S) {
    S.base = new SElemType[MAXSIZE];
    S.top = S.base;
    S.stacksize = MAXSIZE;
}

void Push(SqStack &S, SElemType e) {
    *S.top++ = e;
}

void Pop(SqStack &S, SElemType &e) {
    e = *--S.top;
}

bool Empty(SqStack S) {
    if (S.top == S.base) return true;
    return false;
}

int main() {
    SqStack S;
    InitStack(S);
    int n;
    scanf("%d",&n);
    while (n) {
        Push(S, n%8);
        n/=8;
    }
    while (!Empty(S)) {
        SElemType e;
        Pop(S, e);
        printf("%d",e);
    }
    return 0;
}