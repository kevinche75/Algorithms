#include <iostream>
#include <vector>

using namespace std;

struct pipe {
    int in, out, coast;
};

pipe v[124751];
int main() {

    int n, m;

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        v[i] = {a - 1, b - 1, w};
    }

    int s, f;

    cin >> s >> f;
    s--;
    f--;

    vector<int> res(510, -1);

    res[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (res[v[j].in] != -1 && res[v[j].out] < res[v[j].in] + v[j].coast) {
                res[v[j].out] = res[v[j].in] + v[j].coast;
            }
        }
    }

    if (res[f] != -1) {
        cout << res[f];
    } else {
        cout << "No solution";
    }

    return 0;
}