#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    int n;
    char a[99]={};
    while (scanf("%d",&n) == 1 && n) {
        for (int fghij = 1;fghij <= 98765;++fghij) {
            int ok = 1;
            int abcde = n*fghij;
            sprintf(a,"%05d%05d",abcde,fghij);
            if (strlen(a) > 10) break;
            sort(a,a+10);
            for (int i=1;i<10;++i) {
                if (a[i]!='0' && a[i]==a[i-1]) {
                    ok = 0;break;
                }
            }
            if (ok) {
                printf("%05d/%05d=%d\n",abcde,fghij,n);
            }
        }
        printf("\n");
    }
    return 0;
}
