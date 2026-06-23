/**
输出绝对值。 
格式：
输入：<number>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double n;
	scanf("%lf",&n);
	if (n>=0) printf("%.2lf",n);
	else printf("%.2lf",-n);
	return 0; 
 } 
