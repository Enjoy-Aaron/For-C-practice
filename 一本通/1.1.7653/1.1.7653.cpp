#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,a,y,b;
	double s1,s2,s3;
	cout<<"================================================================"<<endl;
	printf("地球资源够x亿人生活a年或y亿人生活b年。\n");
	printf("请输入...\n") ;
	printf("<x> <a> <y> <b>\n");
	scanf("%d%d%d%d",&x,&a,&y,&b);
	s1=a*x;
	s2=b*y;
	s3=(s1-s2)/(a-b);
	printf("地球最多能够养活的人数: ");
	printf("%.2lf<亿>",s3);
	return 0;
}
