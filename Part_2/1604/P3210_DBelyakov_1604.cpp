#include <iostream>
#include <algorithm>

using namespace std;
struct sign{
    long index;
    long count;
};

int n;
long sum;

sign signs[10001];

int main()
{
    cin >> n;
    int left = 0;
    int right = n-1;
    for (long i = 0; i < n; i++) {
        cin >> signs[i].count;
        signs[i].index = i+1;
        sum +=signs[i].count;
    }

    sort(&signs[0], &signs[n], [](const sign a, const sign b) -> bool{
        return a.count < b.count;
    });

    while(sum > 0){
        cout << signs[right].index << " ";
        signs[right].count--;
        sum--;
        if(signs[left].count != 0){
            cout << signs[left].index << " ";
            signs[left].count--;
            sum--;
        }
        int i = n-1;
        while(i != 0 && signs[i-1].count > signs[i].count){
            swap(signs[i-1], signs[i]);
            i--;
        }
        if(signs[left].count == 0 && left+1!=right) left++;
    }
    return 0;
}