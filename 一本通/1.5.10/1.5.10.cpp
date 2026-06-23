/**
满足条件的数累加。 
格式：
输入：<n>
      <number[1]> <number[2]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,n,s;
	scanf("%d%d",&m,&n);
	for (int i=m;i<=n;++i)
	{
		if (i%17==0) s+=i;
	}
	printf("%d",s);
	return 0;
}
