/**
角谷猜想。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,a;
	scanf("%ld",&n);
	while(n!=1)
	{
		if (n%2==1)
		{
			printf("%ld*3+1=%ld\n",n,n*3+1);
			n=n*3+1;
		}
		else
		{
			printf("%ld/2=%ld\n",n,n/2);
			n/=2;
		}	
	}
	printf("END");
	return 0;
}
