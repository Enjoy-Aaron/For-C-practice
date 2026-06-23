/**
最高的分数。 
格式：
输入：<n>
      <number[1]> <number[2]> ... <number[n]>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double max=-1000000;
	double t;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%lf",&t);
		if (t>max) max=t;
	}
	printf("%g",max);
	return 0;
}
