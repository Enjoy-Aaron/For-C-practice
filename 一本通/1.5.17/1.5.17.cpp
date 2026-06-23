/**
斐波那契数。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,k;
	a=1;b=1;
	scanf("%d",&k);
	for (int i=3;i<=k;++i)
	{
		c=a+b;
		a=b;
		b=c;
	}
	printf("%d",c);
	return 0;;
}
