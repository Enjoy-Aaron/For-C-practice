/**
含k个3的数。 
格式：
输入：<number[1]> <result[2]>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,n,k,s=0,t;
	cin>>m>>k;
	n=m;
	while (n!=0)
	{
		t=n%10;
		if (t==3) s++;
		n/=10;
	}
	if (m%19==0 && s==k) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
