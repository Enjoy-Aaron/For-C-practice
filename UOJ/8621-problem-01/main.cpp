#include <malloc.h>  /* malloc()等 */ 
#include <cstdio>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int ElemType; 
typedef struct /*静态查找表的顺序存储结构 */ 
{ 
	ElemType *elem; /* 数据元素存储空间基址，建表时按实际长度分配，0号单元留空 */ 
	int length; /* 表长度 */ 
}SSTable; 

void Creat_Seq(SSTable &ST,int n) 
{ /* 操作结果: 构造一个含n个数据元素的静态顺序查找表ST(数据来自数组r) */ 
	int i,temp; 
	ST.elem=(ElemType *)malloc((n+1) * sizeof(ElemType)); /* 动态生成n个数据元素空间(0号单元不用) */ 
	if(!(ST).elem) 
	{
		printf("ERROR\n");
		exit(0);
	} /*内存分配失败结束程序*/ 
	for(i=0;i<n;i++) 
	{ 
		scanf("%d",&temp); 
		*(ST.elem+i)=temp; /* 依次赋值给ST */ 
	}
	ST.length=n; 
} 

int Search_Seq(SSTable &ST,ElemType key) 
{ /* 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为 */ 
/* 该元素在表中的位置，否则为-1。算法9.1 */ 
  int l = 0, r = ST.length-1, m;
  while (l <= r) {
    m = l + ((r - l) >> 1);
    if (ST.elem[m] == key) return m;
    if (ST.elem[m] < key) l = m + 1;
    else r = m - 1;
  }
  return -1;
}

int main() 
{ 
	SSTable ST; 
	int loc,key; 
	int n; 
	scanf("%d",&n); 
	Creat_Seq(ST,n); 
	//printf("Please input the key value："); 
	scanf("%d",&key); 
	loc = Search_Seq(ST,key); 
	if(loc!=-1) 
		printf("The element position is %d.\n",loc); 
	else 
		printf("The element is not exist.\n"); 
}
