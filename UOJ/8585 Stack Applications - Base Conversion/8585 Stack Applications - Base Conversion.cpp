#include <iostream>
#include <cstdio>
#define MAXSIZE 100
using namespace std;

typedef struct {
    int *base;
    int *top;
    int stacksize;
}SqStack;

void InitStack(SqStack &S) {
    S.base = new int[MAXSIZE];
    S.stacksize = MAXSIZE;
    S.top = S.base;
}

void Push(SqStack &S, int e) {
    if (S.top - S.base == S.stacksize) return;
    *S.top++ = e;
    return;
}

void Pop(SqStack &S, int &e) {
    if (S.top == S.base) return;
    e = *--S.top;
    return;
}

int GetLength(SqStack S) {
    return S.top - S.base;
}

void GetTop(SqStack S, int &e) {
    if (S.top == S.base) return;
    e = *(S.top - 1);
}

bool Empty(SqStack S) {
    return !(S.top - S.base);
}

int main()
{
    SqStack S;
    InitStack(S);
    int n;
    cin >> n;
    while (n) {
        int e = n % 8;
        n /= 8;
        Push(S, e);
    }
    int e;
    while (!Empty(S)) {
        Pop(S, e);
        printf("%d", e);
    }
    return 0;
}