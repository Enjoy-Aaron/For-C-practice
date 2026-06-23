/**
判断一个整数能否被3,5,7整除。 
格式：
输入：<number1> <number2>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t;
	scanf("%d",&n);
	if (n%3==0) 
	{
		printf("3 ");
		t=1;
	}
	if (n%5==0)
	{
		printf("5 ");
		t=1;
	}
	if (n%7==0)
	{
		printf("7 ");
		t=1;
	}
	if (t==0) printf("NONE");
	return 0;
 } 
