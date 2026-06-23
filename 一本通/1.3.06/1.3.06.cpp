#include <bits/stdc++.h>
using namespace std;

int main()
{
	double a,b;
	double c;
	printf("确诊数：<a>  死亡数：<b>  求死亡率\n");
	for (;;)
	{
		scanf("%d%d",&a,&b);
		if (b/a>1)
		{
			printf("清重新输入...\n");
			continue;
		}
		else
		{ 
			break;
		}
	}
	c=b/a;
	printf("死亡率：%.2lf",c*100);
	printf("% \n");
	return 0;
}

