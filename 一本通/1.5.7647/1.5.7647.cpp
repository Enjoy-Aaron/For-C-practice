/**
余数相同问题。 
格式：
输入：<number[1]> <number[2]> <number[3]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for (int i=2;i<=a;++i)
	{
		if ((a%i==b%i)&&(b%i==c%i))
		{
			printf("%d",i);
			return 0;
		}
	} 
}
