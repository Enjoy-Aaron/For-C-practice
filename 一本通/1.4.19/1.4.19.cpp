/**
简单计算器 
格式：
输入：<number1> <number2> <char>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double a,b,r;
	int t;
	char s;
	scanf("%lf%lf%s",&a,&b,&s);
	switch(s)
	{
		case '+':
			r=a+b;
			t=1;
			break;
		case '-':
			r=a-b;
			t=1;
			break;
		case '*':
			r=a*b;
			t=1;
			break;
		case '/':
			if (b!=0) 
			{
				r=1/b;
				t=1;
			}
			  else printf("Divided by zero!");
			break;
		default:
			printf("invalid operator!");
	}
	if (t==1) printf("%lf",r);
	return 0;
}
