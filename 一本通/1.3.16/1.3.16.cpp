/**
求A(xa,ya),B(xb,yb)的线段长度. 
格式：
输入：<xa> <ya> <xb> <yb>
输出：<AB> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double xa,ya,xb,yb;
	scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
	printf("%.3lf",sqrt(pow(xa-xb,2)+pow(ya-yb,2)));
}
