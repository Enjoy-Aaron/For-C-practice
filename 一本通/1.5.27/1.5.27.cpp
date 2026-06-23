/**
级数求和。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n=1;
	double s=1,k;
	scanf("%lf",&k);
	while (s<=k)
	{
		++n;
		s+=1.00/n;
	}
	printf("%d",n);
	return 0;
}
