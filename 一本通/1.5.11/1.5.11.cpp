/**
整数的个数。 
格式：
输入：<n>
      <number[1]> <number[2]> ... <number[n]> 
输出：<result[1]>
	  <result[2]>
	  <result[3]>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,a=0,b=0,c=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&k);
		if (k==1) ++a;
		if (k==5) ++b;
		if (k==10) ++c;
	}
	printf("%d\n%d\n%d",a,b,c);
	return 0;
}
