#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
        int k;
        while (1) {
            scanf("%d",&k);
            if (k==0) return 0;
            int m = 1;
            while (1) {
                int pos = 0;
                bool flag = 1;
                for (int i=2*k; i>k; i--) {
                    pos = (pos + m) % i;
                    if (pos<k) {
                        flag = 0;break;
                    }
                }
                m++;
                if (flag == 1) break;
            }
            printf("%d\n",m);
        }
    return 0;
}
