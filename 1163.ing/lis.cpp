#include <iostream>

using namespace std;

const int LEN = 3;
const int coins[LEN] = {1, 3, 5};

int calc(int n) {
    if (n == 0) {
        return n;
    }

    int a = 0;
    int b = 0;
    int *min = new int[n];
    min[0] = 0;

    for (int i=1; i<=n; i++) {
        min[i] = min[i-coins[0]] + 1;
        for (int j=1; j<LEN; j++) {
            if (i>=coins[j] && (min[i-coins[j]]+1)<min[i]) {
                min[i] = min[i-coins[j]] + 1;
            }
        }
        if (i==n) {
            return min[i];
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    int ret = calc(n);
    cout << n << ',' << ret << endl;
    return 0;
}

