/**
求阶乘的和。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	unsigned int n;
	long long s=0,t=1;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		t*=i;
		s+=t;
	}
	printf("%ld",s);
	return 0;
}
