/**
骑车与走路。 
格式：
输入：<number>
输出：<result> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double n,b,w;
	scanf("%lf",&n);
	b=n/3+50;
	w=n/1.2;
	if (b>w) printf("Walk");
	if (b==w) printf("All");
	if (b<w) printf("Bike");
	return 0;
}
