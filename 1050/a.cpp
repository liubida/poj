#include <iostream>

using namespace std;

int n, *array;

int calc() {
    for ( int y=0; y<n * n; y++) {
        cout << " " << array[y];
    }
    cout << endl;
}

int main(){
    cin >> n;
    array = new int(n * n);
    for (int x=0; x<n; x++) {
        for ( int y=0; y<n; y++) {
            cin >> array[x * n + y];
        }
    }
    calc();

    return 0;
}



