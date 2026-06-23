/**
点和正方形的关系。 
格式：
输入：<number1> <number2>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double a,b;
	scanf("%lf",&a,&b);
	if ((a>=-1)&&(a<=1)&&(b>=-1)&&(b<=1)) printf("YES");
	  else printf("NO");
	return 0; 
}
