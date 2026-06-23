/**
津津的储存计划。 
格式：
输入：<number[1]>
      <number[2]>
      ...
      <number[12]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x,m,n;
	m=0;n=0;
	for (int i=1;i<=12;++i)
	{
		scanf("%d",&x);
		m+=300-x;
		if (m<0) 
		{
			printf("%d",-i);
			return 0;
		}
		if (m>=100)
		{
			n+=m/100;
			m%=100;
		}
	}
	printf("%d",n*120+m);
	return 0;
}
