/**
判断是否为两位数。 
格式：
输入：<number1>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if ((n>=10)&&(n<=99)) printf("1");
	  else printf("0");
	return 0;
}
