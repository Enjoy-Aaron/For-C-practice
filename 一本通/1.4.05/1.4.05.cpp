/**
整数大小比较。 
格式：
输入：<number1> <number2>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if (a>b) printf(">");
	if (a==b) printf("=");
	if (a<b) printf("<");
	return 0;
 } 
