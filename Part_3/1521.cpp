#include <iostream>

using namespace std;

const int t = (1 << 20) - 1;
int a[2 * t + 2];

void delete_soldier(int y) {
    y += t;
    a[y] = 0;
    for (int i = y / 2; i > 0; i /= 2) {
        a[i] = a[2 * i] + a[2 * i + 1];
    }
}

int get_position(int l, int r){
    int res = 0;
    l += t;
    r += t;
    while (l <= r){
        if (l % 2 == 1) {
            res += a[l];
            l++;
        }
        if (r % 2 == 0){
            res += a[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

int get_index(int v, int l, int r, int x){
    if ((x == a[v]) & (a[v] - a[t + r] < x)){
        return r;
    }
    if (x <= a[2 * v]){
        return get_index(2 * v, l, l + (r - l + 1) / 2 - 1, x);
    } else {
        return get_index(2 * v + 1, l + (r - l + 1) / 2, r, x - a[2 * v]);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        a[t + i] = 1;
    }

    for (int i = t; i >= 1; i--){
        a[i] = a[2 * i] + a[2 * i + 1];
    }

    int index = k, position;
    delete_soldier(k);

    for (int i = 0; i < n - 1; i++){
        cout << index << " ";
        position = (get_position(1, index) + k) % a[1];
        if (position == 0){
            position = a[1];
        }
        index = get_index(1, 1, t + 1, position);
        delete_soldier(index);
    }

    cout << index << endl;

    return 0;
}
