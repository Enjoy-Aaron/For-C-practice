#include <iostream>
#include <cstdio>
using namespace std;

bool solve(int n, int idx) {
    if (n==1 || n==2) return false;
    if (n==3) return true;
    if (idx%2==0) return solve(n/2, idx/2);
    return solve((n+1)/2, (idx+1)/2);
}

int main() {
    int n;
    while (scanf("%d",&n)==1 && n!=0) {
        bool flag=0;
        for (int i=1; i<=n; ++i) {
            if (solve(n, i)==false) {
                printf("%d\n",i);
                flag = 1;
                break;
            }
        }
        if (flag==0) printf("0\n");
    }
    return 0;
}