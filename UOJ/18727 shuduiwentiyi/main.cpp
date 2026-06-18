#include <iostream>
using namespace std;

const int MAX_A = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, C;
    cin >> N >> C;
    
    int cnt[MAX_A + 1] = {0};
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    
    long long ans = 0;
    for (int x = 1; x <= MAX_A; ++x) {
        if (x + C > MAX_A) continue;
        ans += (long long)cnt[x] * cnt[x + C];
    }
    
    cout << ans << endl;
    return 0;
}