/**
判断数正负 
格式：
输入：<number>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if (n>0) printf("positive");
	if (n==0) printf("zero");
	if (n<0) printf("negative");
	return 0;
}
