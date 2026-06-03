#include <iostream>
#include <cstdio>
using namespace std;

void Han(int n, char from, char aux, char to) {
    if (n==1) {
        printf("%c->%d->%c\n",from, n, to);
        return;
    }
    Han(n-1, from, to, aux);
    printf("%c->%d->%c\n", from, n, to);
    Han(n-1, aux, from, to);
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    char a,b,c;
    cin >>a >> b >> c;
    Han(n, a, c, b);
    return 0;
}