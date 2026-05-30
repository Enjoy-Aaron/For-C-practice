#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 101;
int cnt[MAXN];

int main()
{
    for (int num=1;num<=MAXN;++num){
        int tot=0;
        for (int a=1;a<num;++a) {
            for (int b=a;b<num;++b) {
                if (a*a+b*b==num*num) {
                    tot++;
                }
            }
        }
        for (int d=1;d<num;++d){
            if (num*num%d!=0) continue;
            int e = num*num/d;
            if ((e-d)%2==0) {
                tot++;
            }
        }
        cnt[num]=tot;
    }
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        printf("%d\n",cnt[n]);
    }
    return 0;
}
