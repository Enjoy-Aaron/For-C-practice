#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e6+10;

void get_nextval(char s[], int len, int nextval[])
{
    nextval[0] = -1;
    int i=0, j=-1;
    while (i<len) {
        if (j==-1 || s[i] == s[j]) {
            i++;j++;
            if (s[i] == s[j]) {
                nextval[i] = nextval[j];
            }
            else {
                nextval[i] = j;
            }
        }
        else {
            j = nextval[j];
        }
    }
}

int main()
{
    char s[MAXN]={};
    scanf("%s",s);
    int n = strlen(s);
    for (int len = 1; len <=n; ++len) {
        if (n % len != 0) continue;
        int ok = 1;
        for (int i=len; i<n; ++i) {
            if (s[i] != s[i-len]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            printf("%d\n",n/len);
            return 0;
        }
    }
    return 0;
}
