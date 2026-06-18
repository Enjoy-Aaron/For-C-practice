#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow_mod(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, m;
    cin >> n >> m;
    
    long long total = pow_mod(m, n);
    long long valid = (m % MOD) * pow_mod(m - 1, n - 1) % MOD;
    long long ans = (total - valid + MOD) % MOD;
    
    cout << ans << endl;
    return 0;
}