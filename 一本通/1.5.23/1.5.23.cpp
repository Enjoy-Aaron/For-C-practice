/**
药房管理。 
格式：
输入：<m>
	  <n>
      <number[1]> <number[2]> ... <number[n}>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,n,s,f=0;
	scanf("%d",&m);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&s);
		if (s<=m)
		{
			m-=s;
		}
		  else
		  {
			f++; 
		  }
	}
	printf("%d",f);
	return 0;
}
