#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

struct point{
    long x;
    long y;
    int index;
    double angle;
};

point* points;
int n;
int min_point = 0;

void qsort(point *array, int size){

    int i = 0;
    int j = size - 1;

    point middle_point = array[size / 2];

    do{
        while(array[i].angle < middle_point.angle){
            i++;
        }
        while(array[j].angle > middle_point.angle){
            j--;
        }

        if(i <= j){
            point tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    } while (i <=  j);

    if(j > 0) {
        qsort(array, j + 1);
    }
    if(i < size){
        qsort(&array[i], size - i);
    }
}

int main() {
    cin >> n;
    points = new point[n];

    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
        points[i].index = i + 1;
        if(points[i].y < points[min_point].y || points[min_point].y == points[i].y && points[i].x < points[min_point].x){
            min_point = i;
        }
    }

    point tmp = points[0];
    points[0] = points[min_point];
    points[min_point] = tmp;

    for(int i = 1; i < n; i++){
        if(points[i].y == points[0].y) points[i].angle = 0;
        else if (points[i].x == points[0].x) points[i].angle = PI/2;
        else points[i].angle = atan2((double)(points[i].y - points[0].y), (double)(points[i].x - points[0].x));
        if (points[i].angle < 0) points[i].angle += 2 * PI;
    }

    qsort(&points[1], n-1);

    cout << points[0].index << " " << points[n/2].index;

    return 0;
}