/**
输入球的半径，求球的体积。
格式：
输入：<a>
输出：<b> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	float PI=3.14;
	double r;
	scanf("%lf",&r);
	printf("%.2lf",4/3*PI*pow(r,3));
	return 0;
}

