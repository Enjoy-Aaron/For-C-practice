#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[100010]={};
    for (int i=0;i<n;++i) scanf("%d",a+i);
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;++i) {
        int temp;
        scanf("%d",&temp);
        int idx=0;
        while (idx<n && a[idx]<temp) idx++;
        for (int j=n-1;j>=idx;--j) a[j+1] = a[j];
        a[idx] = temp;
        if (n%2==0) printf("%d\n",a[n/2]);
        else {
            double res =1.0 *( a[n/2] + a[n/2+1])/2;
            if (1.0*int(res) == res) printf("%.0lf\n",res);
            else printf("%.1f\n",res);
        }
        n++;
    }
    return 0;
}
