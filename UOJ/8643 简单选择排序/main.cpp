#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int a[1010]={};
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    for (int i=1;i<n;++i) {
        int k=i;
        for (int j=i+1;j<=n;++j) {
            if (a[j]<a[k]) k=j;
        }
        int t = a[i];
        a[i] = a[k];
        a[k] = t;
        for (int i=1;i<=n;++i) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
