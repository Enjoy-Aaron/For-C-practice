/**
统计满足条件的四位数。 
格式：
输入：<n>
      <number[1]> <number[2]> ... <number[n}>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d,n,m,s;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&m);
		a=m/1000;
		b=(m/100)%10;
		c=(m/10)%10;
		d=m%10;
		if (d-a-b-c>0) s++;
	}
	printf("%d",s);
	return 0;
}
