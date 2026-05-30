#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1001;

void Merge(int a[], int l, int mid, int r)
{
    int i=l, j=mid+1, k=l;
    int temp[MAXN]={};
    while (i <= mid && j <=r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <=r) temp[k++] = a[j++];
    for (int x=l; x<=r; ++x) {
        a[x] = temp[x];
    }
    return;
}

void mergeSort(int a[], int l, int r)
{
    if (l>=r) return;
    int mid = (l+r)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    Merge(a,l,mid,r);
    return;
}

int main()
{
    int n,a[MAXN];
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);
    for (int i=0; i<n; ++i) {
        printf("%d ",a[i]);
    }
    return 0;
}
