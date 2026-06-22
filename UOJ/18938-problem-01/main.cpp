#include <iostream>
#include <cstdio>
using namespace std;

void Han(int n, char from, char to, char aux) {
    if (n==1) {
        printf("%c->1->%c\n", from, to);
        return;
    }
    Han(n-1, from, aux, to);
    printf("%c->%d->%c\n", from, n, to);
    Han(n-1, aux, to, from);
    return;
}

int main() {
    int n;
    scanf("%d",&n);
    char a, b, c;
    cin >> a >> b >> c;
    Han(n, a, b, c);
    return 0;
}