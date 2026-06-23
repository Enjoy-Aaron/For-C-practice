/**

格式：
输入：<a>
输出：<b> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h,r,n;
	double PI=3.141592653589793;
	scanf("%d%d",&h,&r);
	n=20*1000/(h*PI*r*r)+1;
	printf("%d",n);
	return 0;
}

