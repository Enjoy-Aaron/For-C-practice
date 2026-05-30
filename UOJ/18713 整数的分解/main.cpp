#include <iostream>
#include <cstdio>
using namespace std;
int n;

void dfs(int sumL, int a[], int pos)
{
    if (sumL == n) {
        printf("%d=",n);
        for (int i=1;i<=a[0]; ++i) {
            if (i!=1) printf("+");
            printf("%d",a[i]);
        }
        printf("\n");
        return;
    }
    for (int i=pos;i>=1;i--) {
        if (sumL + i > n) continue;
        a[++a[0]] = i;
        dfs(sumL+i,a,i);
        a[0]--;
    }
    return;
}

int main()
{
    int a[1001]={};
    a[0] = 0; //0¥Ê¥¢¥Û–°
    scanf("%d",&n);
    dfs(0, a, n);
    return 0;
}
