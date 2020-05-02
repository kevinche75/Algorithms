#include <iostream>
#include <climits>

using namespace std;

void  calcSum (int i, int sum1, int sum2);
int num;
int *arr;
int min_dif = INT_MAX;

int main() {

    cin >> num;

    arr = new int[num];

    for (int i = 0; i < num; i++){
        cin >> arr[i];
    }

    calcSum(0, 0, 0);

    cout << min_dif;

    return 0;
}

void  calcSum(int i, int sum1, int sum2){
    if (i != num) {
        calcSum(i+1, sum1 + arr[i], sum2);
        calcSum(i+1, sum1, sum2 + arr[i]);
    } else {
        if(abs(sum1-sum2) < min_dif){
            min_dif = abs(sum1-sum2);
        }
    }
}