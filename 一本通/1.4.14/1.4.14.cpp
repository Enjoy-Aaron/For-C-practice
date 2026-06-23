/**
计算邮资。 
格式：
输入：<number1> <number2>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,s=8;char w;
	scanf("%d %s",&a,&w);
	if (a>1000) 
	{
		if ((a-1000)%500!=0)
			s+=((a-1000)/500+1)*4;
	 	  else
			s+=(a-1000)/500*4;
	}
	if (w=='y') s+=5;
	printf("%d",s);
	return 0;
}
