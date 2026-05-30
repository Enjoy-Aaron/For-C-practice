#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,a[1010]={};
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    int flag=1;
    for (int i=1;i<=n;++i) {
        if ((2*i<=n && a[2*i]>a[i]) || (2*i+1<=n && a[2*i+1]>a[i])) {
            flag=0;
            break;
        }
    }
    if (flag) printf("Y\n");
    else printf("N\n");
    return 0;
}
