#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5+10;

int main()
{
    int T;
    int a[MAXN];
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i=1;i<=n;++i) {
            cin >> a[i];
        }
        int i=1, j=n;
        while (i<j) {
            while (a[i] < 0 && i<j) i++;
            while (a[j] > 0 && i<j) j--;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        for (int s=1;s<=n;++s) printf("%d ",a[s]);
        printf("\n");
    }
    return 0;
}
