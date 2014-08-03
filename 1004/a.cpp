#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"

using namespace std;

int calc_len(int a) {
    int len = 0;
    int tmp = a;
    while ((tmp /= 10) > 0) {
        len++;
    }
    return len + 1;
}

void to_array(int a, int * arr) {
    int len = calc_len(a);
    int tmp = a;
    for (int i=0; i<len; i++) {
        arr[i] = tmp % 10;
        tmp /= 10;
    }

    cout << "int to array: ";
    for (int i=len-1; i>=0; i--) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}


void add_with_array(int* a, int len_a, int* b, int len_b, int* ret) {
    int max_len = len_a > len_b ? len_a : len_b;
    int min_len = len_a < len_b ? len_a : len_b;
    //int* ret = (int*) malloc((max_len+1) * sizeof(int));
    //int ret[max_len+1];
    cout << "max_len:" << len_a << endl;
    cout << "min_len:" << len_b << endl;

    int i = 0;

    for (i=0; i<min_len; i++) {
        ret[i] = a[i] + b[i];
    }

    cout << "int to array: ";
    for (int i=max_len; i>=0; i--) {
        cout << ret[i] << ' ';
    }
    cout << endl;

    if (i >= len_a) {
        // b is the longer array
        for (; i<max_len; i++) {
            ret[i] = b[i];
        }
    } else {
        // a is the longer array
        for (; i<max_len; i++) {
            ret[i] = a[i];
        }
    }

    int next = 0;
    for (i=0; i<max_len+1; i++) {
        ret[i] += next;
        next = ret[i] / 10;
        ret[i] = ret[i] % 10;
    }

    delete a;
    delete b;
    //free(a);
    //free(b);
}

int main() {
    int MONTH_COUNT = 2;
    int t = 0;
    int* sum_arr = new int[3]();
    int sum_len = 0;
    int next_sum_len = 3;
    double tmp = 0.0;
    int tmp_len = 0;
    int* tmp_arr;
    while (t < MONTH_COUNT) {
        tmp = 0.0;
        cin >> tmp;
        tmp += 0.0001;
        tmp *= 100;
        tmp_len = calc_len(tmp);
        //tmp_arr = (int*)malloc(tmp_len*sizeof(int));
        int* tmp_arr = new int[tmp_len]();
        to_array(tmp, tmp_arr);

        sum_len = next_sum_len;
        int* array = new int[sum_len]();
        memcpy(array, sum_arr, sum_len);
        delete sum_arr;
        cout << tmp_len << ',' << sum_len << endl;
        next_sum_len = 1 + (tmp_len > sum_len ? tmp_len : sum_len);
        sum_arr = new int[next_sum_len];
        add_with_array(tmp_arr, tmp_len, array, sum_len, sum_arr);
        t++;
    }

    cout << sum_len << endl;
    for (int i=sum_len-1; i>=0; i--) {
        cout << sum_arr[i] << ' ';
    }

    return 0;
}
