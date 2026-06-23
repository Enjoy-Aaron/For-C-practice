/**
求小数的某一位数字。 
格式：
输入：<number[a]> <number[b]> <number[n]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	int n,m;
	scanf("%d%d%d",&a,&b,&n);
	for (int i=1;i<=n;++i)
	{
		a*=10;
		m=a/b;
		a%=b;
	}
	printf("%d",m);
	return 0;
}
