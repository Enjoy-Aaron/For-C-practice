/**
与指定数字相同的数的个数。 
格式：
输入：<n> <m> 
      <number[1]> <number[2]> ... <number[n]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k,s;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&k);
		if (k==m) ++s; 
	}
	printf("%d",s);
	return 0;
}
