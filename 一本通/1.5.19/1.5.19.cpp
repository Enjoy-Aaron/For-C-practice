/**
救援。 
格式：
输入：<n>
      <number[A1]> <number[B1]> <number[C1}>
      <number[A2]> <number[B2]> <number[C2}>
      ...
      <number[An]> <number[Bn]> <number[Cn}>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double a,b,s,n,c,l;
	scanf("%lf",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		l=sqrt(a*a+b*b);
		s+=2*l/50+c*1.5;
	}
	printf("%.0lf",ceil(s));
	return 0;
}
