#include <iostream>

using namespace std;

const int MIN = 99999999;
const int LEN = 5;
const int coins[LEN] = {1, 5, 10, 50, 100};

int calc(int n) {
    //cout << n << endl;
    if (n <= 0) {
        return n;
    } else {
        int min = MIN;
        int cur = min;
        for (int i=0; i<LEN; i++) {
            if (n >= coins[i]) {
                cur = calc(n - coins[i]) + 1;
            }
            min = cur < min ? cur : min;
        }
        return min;
    }
}

int main() {
    int n = 0;
    cin >> n;
    int ret = calc(n);
    cout << n << ',' << ret << endl;
    return 0;
}

