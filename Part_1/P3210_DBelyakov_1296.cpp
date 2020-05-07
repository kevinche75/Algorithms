#include <iostream>

using namespace std;

long max_hyper = 0;
int number;
int *arr;

int main() {

    cin >> number;
    arr = new int[number];

    for (int i = 0; i < number; i++){
        cin >> arr[i];
    }

    int sum = arr[0];
    for (int i = 1; i < number; i++){
        sum = max(sum, 0) + arr[i];
        if (sum > max_hyper) max_hyper = sum;
    }

    cout << max_hyper;

    return 0;
}