/**
三角形判断。 
格式：
输入：<number1> <number2> <number3> 
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if ((a+b>c)&&(a-b<c)) printf("YES");
	  else printf("NO");
	return 0;
}
