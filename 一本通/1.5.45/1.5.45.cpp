/**
金币。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,s=0,t=0;
	cin>>n;
	for (int i=1;;++i)
	{
		for (int j=1;j<=i;++j)
		{
			s+=i;
			t++;
			if (t==n)
			{
				printf("%d",s);
				return 0;
			}
		}
	}
	return 0;
}
