#include<malloc.h> 
#include<stdio.h>
#include <iostream>
#include <cstdio>
using namespace std;
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)       
{      
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
// 请补全代码
	S.base = new SElemType[STACK_INIT_SIZE];
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,SElemType e)   
{
// 在栈S中插入元素e为新的栈顶元素
// 请补全代码
	if (S.top - S.base == S.stacksize) return ERROR;
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)   
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
// 请补全代码
	if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

Status GetTop(SqStack S,SElemType &e)   
{ 
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
// 请补全代码
	if (S.top == S.base) return ERROR;
    e = *(S.top-1);
    return OK;
}

int StackLength(SqStack S) 
{
// 返回栈S的元素个数
// 请补全代码
	return S.top - S.base;
}

Status StackTraverse(SqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p  =  S.top;        //请填空
	if(S.base == S.top)printf("The Stack is Empty!"); //请填空
	else
	{
		printf("The Stack is: ");
		while(p != S.base)            //请填空
		{
                       p--;               //请填空
			printf("%d ", *p);
			
		}
	}
	printf("\n");
	return OK;
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
	int len = StackLength(S);
	for (int i=0;i<len;++i) {
		int e;
		Pop(S, e);
		printf("%d",e);
	}
    return 0;
}