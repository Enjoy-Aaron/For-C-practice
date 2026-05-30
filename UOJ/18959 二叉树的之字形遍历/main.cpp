#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e7+10;
char BiTree[MAXN];

int main()
{
    int n=0,l=0;
    for (int i=1;;++i) {
        int flag=0;
        for (int j=1<<(i-1); j<=(1<<i)-1;++j) {
            if (i>1 && BiTree[j/2]=='#') continue;
            char ch;
            cin>>ch;
            if (ch=='#') {
                l++;
            }
            else n++;
            BiTree[j] = ch;
            if (l==n+1) {
                flag=1;
                break;
            }
        }
        if (flag) break;
    }
    n=0,l=0;
    for (int i=1;;++i) {
        int flag=0;
        if (i%2==1) {
            for (int j=1<<(i-1); j<=(1<<i)-1; ++j) {
                if (i>1 && BiTree[j/2]=='#') continue;
                if (BiTree[j]=='#') l++;
                else {
                    n++;
                    printf("%c ",BiTree[j]);
                }
                if (l==n+1) {
                    flag=1;
                    break;
                }
            }
        }
        else {
            for (int j=(1<<i)-1; j>=1<<(i-1); j--) {
                if (i>1 && BiTree[j/2]=='#') continue;
                if (BiTree[j]=='#') l++;
                else {
                    n++;
                    printf("%c ",BiTree[j]);
                }
                if (l==n+1) {
                    flag=1;
                    break;
                }
            }
        }
        printf("\n");
        if (flag) break;
    }
    return 0;
}
