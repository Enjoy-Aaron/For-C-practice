#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1011;
int vis[MAXN];
int a[MAXN];
int A[MAXN];
int s[MAXN];
int cnt;

void solve(int n,int dep)
{
    if (dep==n) {
        for (int i=1;i<n;++i) {
            if (A[i]%2==1 && A[i-1]%2==1) {
                return;
            }
        }
        for (int i=0;i<n;++i) {
            printf("%d ",A[i]);
        }
        printf("\n");
        return;
    }
    for (int i=0;i<cnt;++i) {
        if (vis[s[i]]==0) continue;
        A[dep]=s[i];
        vis[s[i]]--;
        solve(n,dep+1);
        vis[s[i]]++;
    }
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]);
        if (vis[a[i]]==0) {
            vis[a[i]]=1;
            s[cnt++] = a[i];
        }
        else {
            vis[a[i]]++;
        }
    }
    sort(s,s+cnt);
    solve(n,0);
    return 0;
}
