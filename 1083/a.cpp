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

class item {

public:
    int n;
    int ** m;

    item();
    item(int, int **);
};

item::item() {
    n = 0;
    m = NULL;
}

item::item(int a, int ** b) {
    n = a;
    m = b;
}

void echo(item a) {
    cout << a.n << endl;
    for (int i=0; i<a.n; i++) {
        cout << a.m[i][0] << ',' << a.m[i][1] << endl;
    }
}

int main() {
    int total = 0;
    cin >> total;
    
    for (int i=0; i<total; i++) {
        item * a = new item();
        cin >> a -> n;

        int ** c = new int * [2];
        for (int j=0; j< a->n; j++) {
            int * b = new int [2];
            cin >> b[0];
            cin >> b[1];
            c[j] = b;
        }
        a -> m = c;

        echo(*a);
    }


    //  int ** a = new int * [n];
    //  for (int i=0; i<n; i++) {
    //      a[i] = new int[n];
    //  }

    //  for (int i=0; i<n; i++) {
    //      for (int j=0; j<n; j++) {
    //          if (i<j) {
    //              continue;
    //          } else {
    //              cin >> a[i][j] ;
    //          }
    //      }
    //  }

    return 0;
}


