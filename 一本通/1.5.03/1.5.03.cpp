/**
均值。 
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
	double t,s;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%lf",&t);
		s+=t;
	}
	printf("%.4lf",s/n);
	return 0;
}
