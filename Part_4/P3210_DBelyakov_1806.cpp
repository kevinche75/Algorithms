#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;
const int width = 10;
long long pw[width];
int coast[width];

struct Soldier {
    vector<pair<int, Soldier *>> children;
    Soldier *parent{};
    int id{};
    int shortestWay = 500000000;
    bool visited = false;
} soldiers[50000];

map<long long, Soldier*> m;
long long getNumber(long long num, int i) {
    return num / pw[i] % 10;
}

long long changeNumber(long long num, int i, int d) {
    return num -  getDigit(num, i) * pw[i] + d * pw[i];
}

int getPrefix(long long num1, long long num2){
    int prefix = 0;
    for (int i = width - 1; i >= 0; i--)
        if (getDigit(num1, i) == getDigit(num2, i)) prefix++;
        else break;
    return prefix;
}



void checkAndAdd(long long num, int id) {
    vector<pair<int, Soldier *>> v;
    for (int i = 0; i < width; i++)
        for (int d = 0; d < 10; d++) {
            auto changeNum = changedDigit(num, i, d);
            auto neigh = m.find(changeNum);
            if (neigh != m.end())v.emplace_back(coast[getPrefix(num, changeNum)], (*neigh).second);
        }

    for (int i = 0; i < width; i++)
        for (int j = i + 1; j < width; j++) {
            auto di = getDigit(num, i);
            auto dj = getDigit(num, j);
            auto changeNum = changedDigit(changedDigit(num, j, di), i, dj);
            auto neigh = m.find(changeNum);
            if (neigh != m.end())v.emplace_back(coast[getPrefix(num, changeNum)], (*neigh).second);
        }
    m[num] = &soldiers[id];
    soldiers[id].id = id;
    for (auto p : v) {
        p.second->children.emplace_back(p.first, &soldiers[id]);
        soldiers[id].children.emplace_back(p.first, p.second);
    }
}


int main() {
    int n;
    long long b = 1;
    for (long long &i : pw)
        i = b, b*=10;
    cin >> n;
    for (int &i : coast) cin >> i;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        checkAndAdd(num, i);
    }
    queue<Soldier*> q;
    soldiers[0].shortestWay = 0;
    q.push(&soldiers[0]);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node->visited) continue;
        node->visited = true;
        for (auto child = node->children.begin(); child < node->children.end(); child++) {
            auto nd = (*child).second;
            int time = (*child).first;
            if (!nd->visited && nd->shortestWay > node->shortestWay + time) {
                nd->parent = node;
                nd->shortestWay = node->shortestWay + time;
                q.push(nd);
            }
        }
    }

    if (!soldiers[n - 1].visited) {
        cout << "-1";
        return 0;
    }
    cout << soldiers[n - 1].shortestWay << endl;
    vector<Soldier*> result;
    for (Soldier *node = &soldiers[n - 1]; node; node = node->parent)
        result.push_back(node);
    cout << result.size() << endl;
    for (auto it = result.rbegin(); it < result.rend(); it++)
        cout << (1 + (*it)->id) << " ";
}