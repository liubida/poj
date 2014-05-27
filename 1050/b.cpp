#include <iostream>

using namespace std;

int main(){
    int n = 0;
    cin >> n ;
    int array[n];
    int len = sizeof(array) / sizeof(array[0]);

    cout << len << endl;

    return 0;
}

