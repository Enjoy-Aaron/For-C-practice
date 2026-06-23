/**
求一元二次方程。 
格式：
输入：<number1> <number2> <char>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double a,b,c,x,x1,x2,delta;
	scanf("%lf%lf%lf",&a,&b,&c);
	if (a==0) 
	{
		x=-b/c;
		printf("%lf",x);
	}
	  else
	  {
		delta=b*b-4*a*c;
		if (delta>=0)
		{
			x1=(-b+sqrt(delta))/2*a;
			x2=(-b-sqrt(delta))/2*a;
			printf("%.5lf %.5lf",x1,x2);
		}
		  else
		  {
			printf("NONE");
		  }
	  }
	return 0;
}
