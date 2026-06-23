/**
给出一个等差数列的前两项a1,a2，求第n项。 
格式：
输入：<a1> <a2> <n>
输出：<an> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a1,a2,n,an;
	scanf("%d%d%d",&a1,&a2,&n);
	an=a1+(a2-a1)*(n-1);
	printf("%d",an);
	return 0;
}
