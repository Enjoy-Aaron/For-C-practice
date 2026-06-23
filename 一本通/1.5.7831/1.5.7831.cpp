/**
计算星期几。 
格式：
输入：<number[a]> <number[b]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b,n=1;
	scanf("%ld%ld",&a,&b);
	for (int i=1;i<=b;++i)
	n=n*a%7;
	switch(n)
	{
		case 0: printf("Sunday"); break;
		case 1: printf("Monday"); break;
		case 2: printf("Tuesday"); break;
		case 3: printf("Wednesday"); break;
		case 4: printf("Thursday"); break;
		case 5: printf("Friday"); break;
		case 6: printf("Saturday"); break; 
	}
}
