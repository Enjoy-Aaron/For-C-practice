/**
正常血压。 
格式：
输入：<n>
      <number[A1]> <number[B1]>
      <number[A2]> <number[B2]>
      ...
      <number[An]> <number[Bn]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,f=0,m=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		if ((a>=90)&&(a<=140)&&(b>=60)&&(b<=90))
		{
			f++;
			if (f>m) m=f;
		}
		  else f=0;
	}
	printf("%d",m);
	return 0;
}
