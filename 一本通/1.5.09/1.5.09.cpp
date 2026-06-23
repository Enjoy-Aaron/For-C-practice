/**
奇数求和。 
格式：
输入：<n>
      <number[1]> <number[2]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,s;
	scanf("%d%d",&a,&b);
	for (int i=a;i<=b;i++)
	{
		if (i%2!=0) s+=i;
	}
	printf("%d",s);
	return 0;
}
