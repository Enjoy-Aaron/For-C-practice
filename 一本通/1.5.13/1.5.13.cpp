/**
乘方计算
格式：
输入：<number[1]> <number[2]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,n,s=1;
	scanf("%d%d",&a,&n);
	for (int i=1;i<=n;++i)
	{
		s*=a;
	}
	printf("%d",s);
	return 0;
}
