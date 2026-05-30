#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cur = 0, maxn = 0;
    for (char c : s) {
        if (c == 'E') cur += 1;
        else cur -= 1;
        if (cur < 0) cur = 0;
        if (cur > maxn) maxn = cur;
    }
    cout << maxn << endl;
    return 0;
}
