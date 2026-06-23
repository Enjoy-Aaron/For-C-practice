#include <iostream>
#include <cstdio>
using namespace std;

void Han(int n, char from, char to, char aux) {
    if (n==1) {
        printf("%c->%d->%c\n",from, n, to);
        return;
    }
    Han(n-1, from, aux, to);
    printf("%c->%d->%c\n",from, n, to);
    Han(n-1, aux, to, from);
}

int main() {
    int n;char a,b,c;
    cin >> n >> a >> b >> c;
    Han(n,a,b,c);
    return 0;
}