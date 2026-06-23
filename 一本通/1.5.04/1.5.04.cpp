/**
求整数的和与均值。 
格式：
输入：<n>
      <number[1]>
	  <number[2]> 
	  ... 
	  <number[n]>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double s,t;
	scanf("%d",&n);
	s=0;
	for (int i=1;i<=n;++i)
	{
		scanf("%lf",&t);
		s+=t;
	}
	printf("%.0lf %.5lf",s,s/n);
	return 0;
}
