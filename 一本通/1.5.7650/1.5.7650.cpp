/**
不定方程求解。 
格式：
输入：<number[1]> <number[2]> <number[3]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,x,y,s=0;
	cin>>a>>b>>c;
	for (x=0;x<=c/a;++x)
	{
		y=(c-a*x)/b;
		if (a*x+b*y==c)
		{
			s++;
		}
	}
	cout<<s;
	return 0;
}
