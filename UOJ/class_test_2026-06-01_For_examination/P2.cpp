#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1100;
int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<n;++i) {
        int left = 0, right = i-1, tmp = a[i];
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (a[mid] < tmp) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        for (int j=i-1; j>=left; j--) {
            a[j+1] = a[j];
        }
        a[left] = tmp;
        for (int j=0; j<n; ++j) printf("%d ",a[j]);
        printf("\n");
    }
    return 0;
}