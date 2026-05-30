#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 获取E²的所有≤E的因数，按从小到大排序
vector<long long> get_factors(long long E) {
    vector<pair<long long, int>> primes;
    long long temp = E;

    // 质因数分解E
    for (long long i = 2; i * i <= temp; ++i) {
        if (temp % i == 0) {
            int cnt = 0;
            while (temp % i == 0) {
                cnt++;
                temp /= i;
            }
            primes.emplace_back(i, cnt);
        }
    }
    if (temp > 1) {
        primes.emplace_back(temp, 1);
    }

    vector<long long> factors = {1};
    for (auto &p : primes) {
        long long prime = p.first;
        int max_exp = 2 * p.second; // E²的指数是E的2倍
        int sz = factors.size();
        long long current = 1;

        for (int e = 1; e <= max_exp; ++e) {
            current *= prime;
            if (current > E) {
                break; // 后续更大的指数也会超过E，直接跳出
            }
            for (int i = 0; i < sz; ++i) {
                long long new_factor = factors[i] * current;
                if (new_factor <= E) {
                    factors.push_back(new_factor);
                }
            }
        }
    }

    // 排序并去重
    sort(factors.begin(), factors.end());
    auto last = unique(factors.begin(), factors.end());
    factors.erase(last, factors.end());
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    while (cin >> k && k != 0) {
        long long k_squared = k * k;

        // 遍历最右边分母c，从k+1到3k
        for (long long c = k + 1; c <= 3 * k; ++c) {
            // 处理两项拆分
            long long y_minus_k = c - k;
            if (c <= 2 * k && k_squared % y_minus_k == 0) {
                long long x = k + k_squared / y_minus_k;
                cout << "1/" << k << "=1/" << x << "+1/" << c << '\n';
            }

            // 处理三项拆分
            long long D = c - k;
            long long E = k * c;
            vector<long long> ds = get_factors(E);
            long long E_squared = E * E;

            for (long long d : ds) {
                long long d1 = E_squared / d;
                // 检查是否能整除
                if ((d1 + E) % D != 0 || (d + E) % D != 0) {
                    continue;
                }
                long long a = (d1 + E) / D;
                long long b = (d + E) / D;
                if (b >= c) {
                    cout << "1/" << k << "=1/" << a << "+1/" << b << "+1/" << c << '\n';
                }
            }
        }
        // 每个case后输出空行
        cout << '\n';
    }
    return 0;
}
