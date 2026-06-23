#include <bits/stdc++.h>
using namespace std;

int main()
{
	double f,c;
	printf("输入华氏度，输出摄氏度。\n格式：\n<a>\n");
	scanf("%lf",&f);
	c=5*(f-32)/9;
	printf("\n%.5lf摄氏度\n",c);
	return 0;
}
