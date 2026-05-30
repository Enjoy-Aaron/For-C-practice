#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 110;
map<int,int> cnt;

void solve(int n, int *S, int dep, int N, int *A)
{
    if (dep==N) {
        for (int i=0;i<N;++i) {
            printf("%d ",A[i]);
        }
        printf("\n");
        return;
    }
    for (int i=0;i<n;++i) {
        if (dep!=0 && A[dep-1]%2==1 && S[i]%2==1) continue;
        if (cnt[S[i]]) {
            cnt[S[i]]--;
            A[dep]=S[i];
            solve(n,S,dep+1,N,A);
            cnt[S[i]]++;
        }
    }
    return;
}

int main()
{
    int N,n=0;
    int S[MAXN]={},A[MAXN]={};
    scanf("%d",&N);
    for (int i=0;i<N;++i) {
        int temp;
        scanf("%d",&temp);
        if (cnt.find(temp) == cnt.end()) {
            S[n++]=temp;
            cnt[temp]=1;
        }
        else cnt[temp]++;
    }
    sort(S,S+n);
    solve(n,S,0,N,A);
    return 0;
}
