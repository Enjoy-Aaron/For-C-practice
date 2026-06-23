/**
A(Xa,Ya),B(Xb,Yb),C(Xc,Yc);求三角形ABC的面积。 
格式：
输入：<Xa> <Ya> <Xb> <Yb> <Xc> <Yc> 
输出：<S> 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double Xa,Ya,Xb,Yb,Xc,Yc,AB,AC,BC,p,S;
	scanf("%lf%lf%lf%lf%lf%lf",&Xa,&Ya,&Xb,&Yb,&Xc,&Yc);
	AB=sqrt(pow(Xa-Xb,2)+pow(Ya-Yb,2));
	AC=sqrt(pow(Xa-Xc,2)+pow(Ya-Yc,2));
	BC=sqrt(pow(Xb-Xc,2)+pow(Yb-Yc,2));
	p=(AB+AC+BC)/2;
	S=sqrt(p*(p-AB)+p*(p-AC)+p*(p-BC));
	printf("%.2lf",S);
	return 0;
 } 
