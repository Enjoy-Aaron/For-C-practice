/**
数字统计。 
格式：
输入：<number[1]> <number[2]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l,r,i,a,s=0,j;
	scanf("%d%d",&l,&r);
	for (i=l;i<=r;++i)
	{
		a=i;
		do
		{
			j=a%10;
			a/=10;
			if (j==2) s++;
		}
		while (a!=0);
	}
	printf("%d",s);
	return 0;
}

