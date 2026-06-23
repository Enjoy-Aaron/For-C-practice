/**
幂的末尾。 
格式：
输入：<number[1]> <number[2]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,k=1;
	scanf("%d%d",&a,&b);
	for (int i=1;i<=b;++i)
	{
		k*=a;
		k%=1000;
	}
	printf("%03d",k);
	return 0;
}

