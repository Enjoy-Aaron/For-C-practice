#include <iostream>
#include <cstdio>
#include <cstring>
#define MIN(a,b) (a<b? a:b)
using namespace std;

int ToNum(char *s, int left, int right)
{
    int num = 0;
    for (int i=left; i<=right; ++i) {
        num = num*10 + s[i] - '0';
    }
    return num;
}

int main()
{
    char s[20]={};
    scanf("%s",s);
    int n = strlen(s) - 1;
    for (int i=0;i<=2;++i) {
        if (i!=0 && s[0]=='0') continue;
        for (int j=i+1;j<=MIN(n-2, i+3);++j) {
            if (j!=i+1 && s[i+1]=='0') continue;
            for (int k=j+1;k<=MIN(n-1, j+3);++k) {
                if (k!=j+1 && s[j+1]=='0') continue;
                if (k!=n-1 && s[k+1]=='0') continue;
                int num[5]={};
                num[1] = ToNum(s,0,i);
                num[2] = ToNum(s,i+1,j);
                num[3] = ToNum(s, j+1, k);
                num[4] = ToNum(s, k+1,n);
                int ok=1;
                for  (int i=1;i<=4;++i) {
                    if (num[i] <0 || num[i] > 255) {
                        ok=0;
                        break;
                    }
                }
                if (ok) {
                    for (int i=1;i<=4;++i) {
                        printf("%d",num[i]);
                        if (i!=4) printf(".");
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
