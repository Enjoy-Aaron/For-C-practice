#include<malloc.h>
#include <iostream>
#include <cstdio>
#include<stdio.h>
#include <map>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量
using namespace std;
typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

map<char,int> m;
char pec[7][7] = {
    {'>','>','<','<','<','>','>'},
    {'>','>','<','<','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'<','<','<','<','<','=','>'},
    {'=','=','=','=','=','=','>'},
    {'=','=','=','=','=','=','='}
};

typedef struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}SqStack; // 顺序栈

Status InitStack(SqStack &S)
{
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S.base) return ERROR;
	 S.top=S.base;
	 S.stacksize=STACK_INIT_SIZE;
	 return OK;
}

Status Push(SqStack &S,SElemType e)
{
// 在栈S中插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return ERROR;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
     e=*--S.top;
	 return OK;
}

SElemType GetTop(SqStack S)
{
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
    SElemType e =*(S.top-1);
	return e;
}

int StackLength(SqStack S)
{
// 返回栈S的元素个数
	int i;
    i=S.top-S.base;
	return i;
}

Status StackTraverse(SqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p = (SElemType *)malloc(sizeof(SElemType));
	p = S.top;
	if(S.top==S.base)printf("The Stack is Empty!");
	else
	{
		printf("The Stack is: ");
		p--;
		while(p>=S.base)
		{
			printf("%d ", *p);
			p--;
		}
	}
	printf("\n");
	return OK;
}

Status StackEmpty(SqStack S)
{
    if (S.top == S.base) return 1;
    return 0;
}

bool IN(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=') return true;
    return false;
}

int operate(int a,char ch,int b)
{
    switch (ch)
    {
        case '+' : return a+b;
        case '-' : return a-b;
        case '*' : return a*b;
        case '/' : return a/b;
    }
}

char pecedeu(char a, char b)
{
    int ope_a = m[a],ope_b = m[b];
    return pec[ope_a][ope_b];
}

int main()
{
    m['+'] = 0;m['-'] = 1;m['*'] = 2;m['/'] = 3;m['('] = 4;m[')'] = 5;m['='] = 6;
    SqStack OPON,OPTR;
    InitStack(OPON);
    InitStack(OPTR);
    char ch;
    bool flag = 0;
    ch = getchar();
    while (ch != '=' || !StackEmpty(OPTR)) {
        if (!IN(ch)) {
            if (flag == 1) {
                int n;
                Pop(OPON,n);
                n = n*10 + ch - '0';
                Push(OPON,n);
            }
            else Push(OPON,ch - '0');
            ch = getchar();
            flag = 1;
        }
        else {
            flag = 0;
            int x,a,b,c;
            switch (pecedeu(GetTop(OPTR),ch)) {
                case '<' :
                    Push(OPTR,ch);
                    ch = getchar();
                    break;
                case '>' :
                    Pop(OPTR, x);
                    Pop(OPON,b);Pop(OPON,a);
                    c = operate(a,x,b);
                    Push(OPON,c);
                    break;
                case '=' :
                    int e;
                    Pop(OPTR,e);
                    ch = getchar();
                    break;
            }
        }
    }
    printf("%d",GetTop(OPON));
    return 0;
}
