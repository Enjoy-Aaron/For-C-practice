/**
鸡尾酒疗法。 
格式：
输入：<n>
      <number[A1]> <number[B1]> //对照组 
      <number[A2]> <number[B2]>
      ...
      <number[An]> <number[Bn]>
输出：<result[1]>
	  <result[2]>
	  ...
	  <result[n]>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double n,a,b;
	double x,y;
	scanf("%lf",&n);
	scanf("%lf%lf",&a,&b);
	x=b/a;
	for (int i=1;i<=n-1;++i)
	{
		scanf("%lf%lf",&a,&b);
		y=b/a;
		if (x-y>0.05) printf("worse\n");
		if ((x-y>=-0.05)&&(x-y<=0.05)) printf("same\n");
		if (y-x>0.05) printf("better\n");
	}
	return 0;
}
