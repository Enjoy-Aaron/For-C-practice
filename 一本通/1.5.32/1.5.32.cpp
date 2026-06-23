/**
求分数序列和。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double a=1,b=1,c,s=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		c=a+b;
		b=a;
		a=c;
		s+=a/b;
	}
	printf("%.4lf",s);
	return 0;
}
