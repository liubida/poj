#include <iostream>

using namespace std;

#define INT_MIN 0x80000000

int maxSubSum(int *b, int n) {
    int sum = b[0];
    int max = b[0];

    for (int i=1; i<n; i++) {
        if (sum + b[i] >= 0) {
            sum += b[i];
            max = max > sum ? max : sum;
        } else {
            sum = 0;
        }
    }

    return max;
}

int sum(int *array, int x, int y, int k, int n) {
    int ret = 0;

    for (int i=0; i<=(y-x); i++) {
        ret += array[(x+i)*n + k];
    }

    return ret;
}

int calc(int *array, int n) {
    int max = INT_MIN;
    int tmp = 0;

    int b[n];
    //int *b = new int(n);

    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            for (int k=0; k<n; k++) {
                b[k] = sum(array, i, j, k, n);
            }
            tmp = maxSubSum(b, n);
            max = max > tmp ? max : tmp;
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

