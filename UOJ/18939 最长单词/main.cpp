#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;

int main()
{
    char str[100];
    char ch;
    int n=0;
    while (1) {
        scanf("%c",&ch);
        str[n++] = ch;
        if (ch == '.') break;
    }
    int cnt = 0, max_cnt = 0, index;
    for (int i=0;i<n;++i) {
        if (str[i] == ' ' || str[i] == '.') {
            if (cnt > max_cnt) {
                max_cnt = cnt;
                index = i;
            }
            cnt = 0;
            if (str[i] == '.') break;
            continue;
        }
        cnt++;
    }
    for (int i=index-max_cnt;i<index;++i) printf("%c",str[i]);
    return 0;
}
