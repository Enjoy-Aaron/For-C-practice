#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[50];
    for (int i=0;i<n;++i) cin >> a[i];
    int tmp;
    cin >> tmp;
    int l = 0, r = n-1, m;
    while (l<=r) {
        m = (l + r) >> 1;
        if (a[m] <= tmp) l = m + 1;
        else r = m - 1;
    }
    n = n >= l+1 ? n : l+1;
    a[l] = tmp;
    for (int i=0;i<n; ++i) {
        printf("%d ",a[i]);
    }
    return 0;
}