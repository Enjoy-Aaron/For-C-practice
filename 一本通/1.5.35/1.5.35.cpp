/**
求e的值。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long t=1;
	double e=1;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		t*=i;
		e+=1.0/t;
	}
	printf("%.10lf",e);
	return 0;
}
	
  
