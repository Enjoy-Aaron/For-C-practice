/**
最大数输出。 
格式：
输入：<number1> <number2> <number3>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,m;
	scanf("%d%d%d",&a,&b,&c);
	if ((a>=b)&&(a>=c)) m=a;
	if ((b>=a)&&(b>=c)) m=b;
	if ((c>=a)&&(c>=b)) m=c;
	printf("%d",m);
	return 0;
}
