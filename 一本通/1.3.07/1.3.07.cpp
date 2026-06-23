#include <bits/stdc++.h>
using namespace std;

int main()
{
	double a,b,c,d,x;
	double f;
	printf("f(x)=ax^3+bx^2+cx+d\n");
	printf("∏Ò Ω£∫<a> <b> <c> <d>\n<x>\n");
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	scanf("%lf",&x);
	printf("\nf(x)=%.2lf*x^3+%.2lf*x^2+%.2lf*x+%.2lf\n",a,b,c,d);
	printf("x = %.2lf\n",x);
	f=a*x*x*x+b*x*x+c*x+d;
	printf("\nf(x)=%.7lf\n",f);
	return 0;
}
