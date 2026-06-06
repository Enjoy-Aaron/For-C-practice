#include <cstdio>
using namespace std;

void swap(int &a, int &b) {
    int t=a;a=b;b=t;
    return;
}

void solve(int *a, int len) {
    int i=0, j=len-1;
    while (i < j) {
        while (i<j && a[i] < 0) ++i;
        while (i<j && a[j] >= 0) --j;
        swap(a[i], a[j]);
        i++;
        j--;
    }
    return;
}

int main() {
    int T,n, a[100010]={};
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=0;i<n;++i)
            scanf("%d",&a[i]);
        solve(a, n);
        for (int i=0;i<n;++i)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}