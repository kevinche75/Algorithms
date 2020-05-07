#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool comp1(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

bool comp2(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int m, n, k;
    int res = 0;

    int p_i = 0, p_k = 0;

    cin >> m >> n >> k;

    pair<int, int> point[180000];
    pair<int, int> single_point[180000];

    for (int i = 0; i < k; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
        point[p_i++] = p;
    }

    for (int i = 0; i < m; i++) {
        pair<int, int> p = {i, -1};
        pair<int, int> p2 = {i, n};
        point[p_i++] = p2;
        point[p_i++] = p;
    }

    for (int i = 0; i < n; i++) {
        pair<int, int> p = {-1, i};
        pair<int, int> p2 = {m, i};
        point[p_i++] = p2;
        point[p_i++] = p;
    }

    sort(&point[0], &point[p_i], comp1);

    for (int i = 0; i < p_i; i++) {
        if (point[i].first == point[i + 1].first) {
            if (point[i + 1].second - point[i].second - 1 > 1) {
                res++;
            } else if (point[i + 1].second - point[i].second - 1 == 1) {
                pair<int, int> p(point[i].first, point[i].second + 1);
                single_point[p_k++] = p;
            }
        }
    }

    sort(&point[0], &point[p_i], comp2);

    for (int i = 0; i < p_i; i++) {
        if (point[i].second == point[i + 1].second) {
            if (point[i + 1].first - point[i].first - 1 > 1) {
                res++;
            } else if (point[i + 1].first - point[i].first - 1 == 1) {
                pair<int, int> p(point[i].first + 1, point[i].second);
                single_point[p_k++] = p;
            }
        }
    }

    sort(&single_point[0], &single_point[p_k+1], comp1);

    if (p_k + 1 > 1) {
        for (int i = 0; i < p_k; i++) {
            if (single_point[i] == single_point[i + 1]) {
                res++;
                i++;
            }
        }
    }

    cout << res;

    return 0;
}