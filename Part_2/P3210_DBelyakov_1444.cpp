#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define PI 3.14159265358979323846
#define EPS 1e-10

struct point {
    long x;
    long y;
    double angle;
    int index;
    double r;
};

point points[30001];

int main() {
    int n;

    cin >> n;
    cin >> points[0].x;
    cin >> points[0].y;
    points[0].index = 0;

    for (int i = 1; i < n; i++) {
        cin >> points[i].x;
        cin >> points[i].y;
        points[i].index = i + 1;

        if (points[i].x == points[0].x) {
            points[i].angle = (points[i].y > points[0].y) ? PI/2 : -PI/2;
            points[i].r = abs(points[i].y - points[0].y);
            continue;
        }

        points[i].angle = atan2((double) (points[i].y - points[0].y),(points[i].x - points[0].x));

        points[i].r = sqrt((double) (pow((points[i].x - points[0].x), 2) + pow((points[i].y - points[0].y), 2)));
    }

    sort(&points[1], &points[n], [](point p1, point p2) -> bool{
        if (abs(p1.angle - p2.angle) > EPS) {
            return p1.angle < p2.angle;
        }

        return p1.r < p2.r;
    });

    double max_a = PI * 2 + points[1].angle - points[n - 1].angle;
    int k = 1;

    for (int i = 1; i < n - 1; i++) {
        if (points[i + 1].angle - points[i].angle > max_a) {
            max_a = points[i + 1].angle - points[i].angle;
            k = i + 1;
        }
    }

    cout << n << endl;
    cout << 1 << endl;

    for (int i = k; i < n; i++) {
        cout << points[i].index << endl;
    }

    for (int i = 1; i < k; i++) {
        cout << points[i].index << endl;
    }

    return 0;
}