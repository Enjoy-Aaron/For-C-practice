#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, C;
    cin >> N >> C;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        long long target = a[i] + C;
        auto left = lower_bound(a.begin(), a.end(), target);
        auto right = upper_bound(a.begin(), a.end(), target);
        ans += right - left;
    }
    
    cout << ans << endl;
    return 0;
}