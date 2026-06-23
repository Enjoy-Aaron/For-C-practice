/**
最大跨度值。 
格式：
输入：<n>
      <number[1]> <number[2]> ... <number[n]>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t,max=-1000000,min=1000000;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&t);
		if (t>max) max=t;
		if (t<min) min=t;
	}
	printf("%d",max-min);
	return 0;
}

