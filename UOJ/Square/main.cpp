#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int l[30],one,n;
bool mark[30], flag;

bool cmp(int a,int b)
{
    return a>b;
}

void dfs(int onel, int num, int pos)
{
    if (flag == true) return;
    if (num==3) {
        flag=1;
        return;
    }
    if (onel==0) {
        num++;
        onel = one;
        pos=0;
    }
    for (int i=pos;i<n;++i) {
        if (mark[i] || l[i]>onel) continue;
        mark[i]=true;
        dfs(onel-l[i],num,i+1);
        mark[i]=false;
    }
}

int main()
{
    while (scanf("%d",&n)==1) {
        flag=0;
        fill(mark,mark+30,false);
        int sum=0;
        for (int i=0;i<n;++i) {
            scanf("%d",l+i);
            sum+=l[i];
        }
        one = sum/4;
        sort(l,l+n,cmp);
        if (l[0]>one || sum%4!=0) {
            printf("no\n");
        }
        else {
            dfs(one,0,0);
            if (flag) {
                printf("yes\n");
            }
            else printf("no\n");
        }
    }
    return 0;
}
