/**
计算多项式的值。 
格式：
输入：<number[1]> <number[2]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	float x,s=1,t=1;
	int n;
	scanf("%f%d",&x,&n);
	for (int i=1;i<=n;++i)
	{
		t*=x;
		s+=t;
	}
	printf("%.2f",s);
	return 0;
} 

