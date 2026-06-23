/**
画矩形。 
格式：
输入：<number[1]> <number[2]> <char> <bool>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,i,j;
	bool flag;
	char a;
	cin>>x>>y>>a>>flag;
	if(flag)
	{
		for (i=1;i<=x;++i)
		{
			for (j=1;j<=y;++j)
			{
				cout<<a;
			}
		cout<<endl;
		}
	}
	else
	{
		for (i=1;i<=x;++i)
		{
			for (j=1;j<=y;++j)
			{
				if ((i!=1)&&(i!=x)&&(j!=1)&&(j!=y))
				{
					cout<<" ";
				}
				else
				{
					cout<<a;
				}
			}
		cout<<endl;
		}
	}
	return 0;
}
