#include <bits/stdc++.h>
using namespace std;

int main()
{
	double r1,r2,R;
	printf("输入电阻r1,r2;	求r1,r2并联时的电阻大小。\n格式；\n<a> <b>\n"); 
	scanf("%lf%lf",&r1,&r2);
	R=1/(1/r1+1/r2);
	printf("\nR = %.2lf\n",R);
	return 0;
}
