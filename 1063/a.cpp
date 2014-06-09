#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int haha(int a, int b) {
    return a > b ? a-b : b-a;
}

int main() {
    int t;
    int n;
    int cur;
    int count_odd = 0;
    int count_even = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> cur;
            // total is odd continue
            if (n&1) { continue; }

            // total is even, calc
            if (i&1) {
                if (cur == 1) { count_odd++; }
                // count_odd += cur;
            } else {
                if (cur == 1) { count_even++; }
                // count_even += cur;
            }
        }
        if (n&1) { 
            cout << "YES" << endl; 
        } else {
            if (haha(count_even, count_odd) <= 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        count_odd = 0;
        count_even = 0;
    }

    return 0;
}
