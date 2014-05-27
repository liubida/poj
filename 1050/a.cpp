#include <iostream>

using namespace std;

int n;
short *array;

int sum(int start, int end) {
    int tmp = 0;
    for (int i=start; i<=end; i++) {
        if (i%n >= start%n) {
            tmp += array[i];
        }
    }
    return tmp;
}

int calc() {
    int max = -999;
    int tmp = 0;

    for (int i=0; i<n*n; i++) {
        for (int j=i; j<n*n; j++) {
            if (i%n <= j%n) {
                tmp = sum(i, j);
                max = (max >= tmp) ? max : tmp;
                //cout << max << ',' << i << ',' << j << endl;
            }
        }
    }
    cout << max << endl;
}

int main(){
    cin >> n;
    array = new short(n * n);
    for (int x=0; x<n; x++) {
        for ( int y=0; y<n; y++) {
            cin >> array[x * n + y];
        }
    }
    calc();

    return 0;
}


