#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)
using namespace std;
const int MAXN = 110;
int n,l[MAXN];
bool flag, mark[MAXN];

bool cmp(int a,int b)
{
    return a>b;
}

void solve(int L, int num, int total_num, int pos, int const_L)
{
    if (flag==1) return;
    if (num==total_num-1) {
        flag=1;
        return;
    }
    if (L==0) {
        num++;
        pos=0;
        L=const_L;
    }
    for (int i=pos; i<n;++i) {
        if (mark[i]==true || l[i]>L) continue;
        mark[i] = true;
        solve(L-l[i], num, total_num, i+1, const_L);
        mark[i] = false;
    }
}

int main()
{
    while (scanf("%d",&n)==1 && n!=0) {
        int total = 0, maxl = 0;
        flag = 0;
        for (int i=0;i<n;++i) {
            scanf("%d",&l[i]);
            total += l[i];
            maxl = MAX(maxl, l[i]);
        }
        sort(l,l+n,cmp);
        for (int L=maxl;L<=total;++L) {
            if (total%L!=0) continue;
            flag = 0;
            int total_num = total / L;
            solve(L, 0, total_num, 0, L);
            if (flag==1) {
                printf("%d\n",L);
                break;
            }
        }
    }
    return 0;
}
