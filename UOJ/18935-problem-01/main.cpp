#include <cstdio>
using namespace std;
typedef long long ll;

ll check(int x, int n) {
    ll sum = 0;
    int cur = x;
    for (int i = 0; i < n; ++i) {
        sum += cur;
        cur = (cur + 1) / 2;
    }
    return sum;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int left = 1, right = M;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        ll total = check(mid, N);
        if (total <= M) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}