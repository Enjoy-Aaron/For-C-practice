#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)
using namespace std;

bool solve(int n,int m)
{
    if (n==1 || n==2) return false;
    if (n==3) return true;
    if (m&1) return solve((n+1)/2,(m+1)/2);
    else return solve(n/2,m/2);
}

int main()
{
    int n,m;
    while (1) {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0) break;
        if (solve(n,m)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
