/**
一箱苹果n个，小虫每x小时吃一个水果，过了y小时后还剩多少个苹果。 
格式：
输入：<n> <x> <y>
输出：<number> 
**/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double n,x,y,a,b;
	scanf("%lf%lf%lf",&n,&x,&y);
	a=y/x;
	b=n-ceil(a);
	if (b<0) b=0;
	printf("%.0 lf",b);
	return 0;
}
