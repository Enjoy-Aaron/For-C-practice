#include <iostream>
#include <cstdio>
using namespace std;

void print_subset(int n, int *A, int cur)
{
    for (int i=0; i<cur; ++i) {
        printf("%d ",A[i]);
    }
    printf("\n");
    int s = cur? A[cur-1] +1 : 1;
    for (int i=s;i<=n;++i) {
        A[cur] = i;
        print_subset(n, A, cur+1);
    }
    return;
}

int main()
{
    int n, A[1001]={};
    scanf("%d",&n);
    print_subset(n, A,0);
    return 0;
}
