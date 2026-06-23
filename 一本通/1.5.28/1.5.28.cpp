/**
分离整数的各个数。 
格式：
输入：<number>
输出：<result[1]> <result[2]> ... <result[n]>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b;
	cin>>n;
	while (n!=0)
	{
		printf("%d ",n%10);
		n/=10;
	}
	return 0;
}
