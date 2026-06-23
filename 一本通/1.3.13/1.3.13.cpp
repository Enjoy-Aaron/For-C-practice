/**
将一个三位数反向输出。 
格式：
输入：<a>
输出：<b> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,n,m;
	scanf("%d",&n);
	a=(n/100)%10;
	b=(n/10)%10;
	c=(n/1)%10;
	m=c*100+b*10+a*1;
	printf("%d",m);
	return 0;
}

