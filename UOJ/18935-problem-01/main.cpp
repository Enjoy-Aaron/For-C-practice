#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int left = 1, right = M;
    int answer = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long total = 0;
        int current = mid;

        for (int i = 0; i < N; ++i) {
            total += current;
            if (total > M) break;
            current = (current + 1) / 2; 
        }

        if (total <= M) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}