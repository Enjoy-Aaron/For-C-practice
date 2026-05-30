#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
map<ll,ll> dp;

bool solve(int n,int idx)
{
    if (n==1 || n==2) return 0;
    if (n==3) return 1;
    if (idx%2==0) return solve(n/2, idx/2);
    return solve((n+1)/2,(idx+1)/2);
}

int main()
{
    int n,idx;
    while (scanf("%d%d",&n,&idx)==2 && n!=0 && idx!=0) {
        if (solve(n,idx)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
