/**
第n小的数。 
格式：
输入：<number>
输出：<result>
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,s=0;
	scanf("%d",&n);
	for (i=2;;++i)
	{
		int x=2;
		while (x<=floor(sqrt(i))&&i%x!=0)
		{
			x++;
		}
		if (x>floor(sqrt(i)))
		{
			s++;
			if (s==n)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
