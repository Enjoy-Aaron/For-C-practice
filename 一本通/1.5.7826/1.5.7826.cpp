/**
分苹果 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long s=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		s+=i;
	}
	printf("%d",s);
	return 0;
}
