/**
计算分数加减表达式的值。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double s=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		if (i%2==1)
		{
			s+=1.0/i;
		}
		if (i%2==0)
		{
			s+=-1.0/i;
		}
	}
	printf("%.4lf",s);
	return 0;
}
