#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e6;
int a[MAXN];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]);
    }
    sort(a, a+n);
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;++i) {
        int tmp;
        scanf("%d",&tmp);
        int j=0;
        while (j<n && a[j]<=tmp) j++;
        for (int k=n-1; k>=j; k--) {
            a[k+1] = a[k];
        }
        a[j] = tmp;
        n++;
        if (n%2 == 0) {
            int ans = (a[n/2-1] + a[n/2]);
            if (ans%2==0) printf("%d\n",ans/2);
            else printf("%.1lf\n",ans/2.0);
        }
        else {
            int ans = a[n/2];
            printf("%d\n",ans);
        }
    }
    return 0;
}