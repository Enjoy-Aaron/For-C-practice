/**
与7无关的数。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long s=0;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		if ((i%7!=0)&&(i/10!=7)&&(i%10!=7))
		{
			s+=i*i;
		}
	}
	cout<<s<<endl;
	return 0;
}
 
