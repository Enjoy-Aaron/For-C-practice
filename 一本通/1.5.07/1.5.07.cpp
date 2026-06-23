/**
奥运奖牌计数 
格式：
输入：<n>
      <number[a1]> <number[b1]> <number[c1]>
      <number[b2]> <number[b2]> <number[c2]>
      ...
      <number[an]> <number[bn]> <number[cn]>
输出：<result[a]> <result[b]> <result[c]> <result[all]> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,n,x,y,z;
	scanf("%d",&n);
	x=0;y=0;z=0;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		x+=a;
		y+=b;
		z+=c;
	}
	printf("%d %d %d %d",x,y,z,x+y+z);
	return 0;
}
