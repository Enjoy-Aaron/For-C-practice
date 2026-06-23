/**
有一门课不及格的学生。 
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
	if ((a<60)||(b<60)) printf("1");
	  else printf("0");
	return 0;
}
