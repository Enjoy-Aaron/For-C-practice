#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> h(n);
    ll max_h = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if (h[i] > max_h) max_h = h[i];
    }
    
    ll left = 1;
    ll right = (max_h + b - 1) / b;
    
    while (left < right) {
        ll mid = left + (right - left) / 2;
        ll sum_x = 0;
        bool feasible = true;
        
        for (ll hi : h) {
            ll base_damage = mid * b;
            if (base_damage >= hi) continue;
            
            ll need = hi - base_damage;
            ll x = (need + a - 1) / a;
            sum_x += x;
            
            if (sum_x > mid) {
                feasible = false;
                break;
            }
        }
        
        if (feasible) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    return 0;
}