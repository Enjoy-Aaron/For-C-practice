#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 100;

void print_subset(int n, int* B, int cur)
{
    if (cur == n) {
        for (int i=0; i<n; ++i) {
            if (B[i] == 1)  printf("%d ",i);
        }
        printf("\n");
        return;
    }
    B[cur] = 1;
    print_subset(n, B, cur+1);
    B[cur] = 0;
    print_subset(n, B, cur + 1);
    return;
}

int main()
{
    int n, B[MAXN]={};
    scanf("%d",&n);
    print_subset(n, B, 0);
    return 0;
}
