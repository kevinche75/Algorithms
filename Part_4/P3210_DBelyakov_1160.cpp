#include <iostream>
#include <algorithm>
using namespace std;

struct cabel {
    int a, b, len;
};

bool comparator (cabel a, cabel b) {
    return a.len < b.len;
}

int n, m, parent[1010], size[1010], count_of_sets = 0, count_of_cabels;
cabel cabels[16000];

void make_set (int w) {
    parent[w] = w;
    size[w] = 1;
    count_of_sets++;
}

int find_set (int w) {
    if (parent[w] == w)
        return w;
    return parent[w] = find_set(parent[w]);
}

void union_sets (int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        count_of_sets--;
    }
}



int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        make_set(i);
    for (int i = 0; i < m; i++) {
        cin >> cabels[i].a >> cabels[i].b >> cabels[i].len;
    }
    sort(cabels, cabels + m, comparatorForCabels);
    for (int i = 0; i < m; i++) {
        if (count_of_sets != 1) {
            union_sets(cabels[i].a, cabels[i].b);
        }
        if (count_of_sets == 1) {
            count_of_cabels = i + 1;
            cout << cabels[i].len << endl << count_of_cabels << endl;
            break;
        }
    }
    for (int i = 0; i < count_of_cabels; i++) {
        cout << cabels[i].a << " " << cabels[i].b << endl;
    }
}