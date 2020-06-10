#include <iostream>
#include <queue>
using namespace std;

int color[110];
vector <int> g[110];

bool bfs (int start) {
    queue <int> que;
    que.push(start);
    while (!que.empty()) {
        int current = que.front();
        que.pop();
        for (int i = 0; i < g[current].size(); i++) {
            int neighbour = g[current][i];
            if (color[neighbour] == -1) {
                color[neighbour] = !color[current];
                que.push(neighbour);
            } else {
                if (color[neighbour] == color[current]) return false;
            }
        }
    }
    return true;
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        while (cin >> x) {
            if (x == 0) break;
            g[i].push_back(x - 1);
            g[x - 1].push_back(i);
        }
    }
    color[0] = 0;
    bool result = bfs(0);
    for (int i = 1; i < n; i++) {
        if (!result){
            cout << -1;
            return  0;
        }
        if (color[i] == -1) {
            color[i] = 0;
            result = bfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << color[i];
    }
    return  0;
}