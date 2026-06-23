/**
判断一个数能否同时被3,5整除。 
格式：
输入：<number1> 
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if ((n%3==0)&&(n%5==0))
		printf("YES");
	  else
		printf("NO");
	return 0;
}
