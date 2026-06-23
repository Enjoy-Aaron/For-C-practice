/**
数1的个数。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,n,a,s=1,j;
	scanf("%d",&n);
	for (i=2;i<=n;++i)
	{
		a=i;
		do
		{
			j=a%10;
			a=a/10;
			if (j==1) s++;
		}
		while (a!=0);
	}
	printf("%d",s);
	return 0;
}

