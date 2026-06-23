#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
const int MAXN = 1e5+10;
int a[MAXN];

int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    scanf("%d",&m);
    while (m--) {
        int tmp;
        scanf("%d",&tmp);
        int j=1;
        while (j<=n && a[j] <= tmp) {
            j++;
        }
        for (int s=n; s>=j; s--) {
            a[s+1] = a[s];
        }
        a[j] = tmp;
        n++;
        if (n%2==0) {
            double res = 1.0 * (a[n/2] + a[n/2+1])/2;
            if (res == int (res)) {
                printf("%.0lf\n", res);
            }
            else printf("%.1lf\n",res);
        }
        else {
            printf("%d\n", a[n/2+1]);
        }
    }
    return 0;
}
