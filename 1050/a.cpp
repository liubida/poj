#include <iostream>
#include <stdlib.h>

using namespace std;

#define INT_MIN 0x80000000

int sum(int * array, int n, int start, int end) {
    int tmp = 0;
    for (int i=start; i<=end; i++) {
        if (i%n >= start%n && i%n <= end%n) {
            tmp += array[i];
        }
    }
    return tmp;
}

int calc(int * array, int n) {
    int max = INT_MIN;
    int tmp = 0;

    for (int i=0; i<n*n; i++) {
        for (int j=i; j<n*n; j++) {
            if (i%n <= j%n) {
                tmp = sum(array, n, i, j);
                max = (max >= tmp) ? max : tmp;
                //cout << max << ',' << i << ',' << j << endl;
            }
        }
    }
    cout << max << endl;
}

int main(){
    int n = 0;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int array[n*n];
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            //array[x * n + y] = rand();
            cin >> array[x * n + y];
        }
    }
    calc(array, n);

    return 0;
}

