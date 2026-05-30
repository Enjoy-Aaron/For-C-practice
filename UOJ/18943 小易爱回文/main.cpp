#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5+10;
int next[MAXN];

void get_next(string T)
{
    next[0]=-1;
    int i=1,j=0;
    while (i<T.length()) {
        if (T[i]==T[j]) {
            i++;j++;
            next[i] = j;
        }
    }
}

void kmp()
{

    return;
}

int main()
{

    return 0;
}
