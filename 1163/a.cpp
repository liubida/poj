#include <iostream>

using namespace std;

int _max(int a, int b) {
    return a > b ? a : b;
}

int calc(int ** a, const int n) {
    int ** s = new int * [n];
    for (int i=0; i<n; i++) {
        s[i] = new int[n];
    }

    s[0][0] = a[0][0];
    int m = s[0][0];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j>i) {
                s[i][j] = -1;
            } else {
                if (i==0 && j==0) {
                    s[i][j] = a[0][0];
                } else {
                    if (j>=1) {
                        s[i][j] = a[i][j] + _max(s[i-1][j-1], s[i-1][j]);
                    } else {
                        s[i][j] = a[i][j] + s[i-1][j];
                    }
                }
            }
            m = m > s[i][j] ? m : s[i][j];
        }
    }

    return m;
}

int main() {
    int n = 0;
    cin >> n;
    
    int ** a = new int * [n];
    for (int i=0; i<n; i++) {
        a[i] = new int[n];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i<j) {
                continue;
            } else {
                cin >> a[i][j] ;
            }
        }
    }

    int ret = calc(a, n);

    //for (int i=0; i<n; i++) {
    //    for (int j=0; j<n; j++) {
    //        cout << a[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    cout << ret << endl;
    return 0;
}

