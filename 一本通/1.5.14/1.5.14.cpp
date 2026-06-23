/**
人口增长。 
格式：
输入：<number[1]> <number[2]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double x,n;
	scanf("%lf%lf",&x,&n);
	for (int i=1;i<=n;++i)
	{
		x*=1+0.001;
	}
	printf("%.4lf",x);
	return 0;
}
