#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  255 	//用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN+1];	//0号单元存放串的长度

void get_next(SString T,int next[]){
// 算法4.7
// 求模式串T的next函数值并存入数组next
   // 请补全代码
    int idx=1, idy=0;
    int len = T[0];
    next[1] = 0;
    while (idx < len) {
        if (idy == 0 || T[idx] == T[idy]) {
            idx++;
            idy++;
            if (T[idx] == T[idy]) next[idx] = next[idy];
            else next[idx] = idy;
        }
        else {
            idy = next[idy];
        }
    }
}

int Index_KMP(SString S,SString T,int pos){
// 算法4.6
// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置
// KMP算法。请补全代码
    int next[MAXSTRLEN];
    get_next(T, next);
    int len1 = S[0];
    int len2 = T[0];
    int idx = pos, idy = 1;
    while (idx <= len1 && idy <= len2) {
        if (idy == 0 || S[idx] == T[idy]) {
            idx++; idy++;
        }
        else {
            idy = next[idy];
        }
    }
    if (idy > len2) {
        return idx - len2;
    }
    return 0;

}
int main()
{
SString T,S;
 int i,j,n;
 char ch;
 int pos;
 scanf("%d",&n);    // 指定n对需进行模式匹配的字符串
ch=getchar();
for(j=1;j<=n;j++)
{
ch=getchar();
  for( i=1;i<=MAXSTRLEN&&(ch!='\n');i++)    // 录入主串
  {
S[i]=ch;
  ch=getchar();
}
S[0]=i-1;    // S[0]用于存储主串中字符个数
ch=getchar();
for( i=1;i<=MAXSTRLEN&&(ch!='\n');i++)    // 录入模式串
{
  T[i]=ch;
  ch=getchar();
}
T[0]=i-1;    // T[0]用于存储模式串中字符个数
pos = 1;
pos=Index_KMP(S, T, pos);    // 请填空
printf("%d\n",pos);
}
    }
