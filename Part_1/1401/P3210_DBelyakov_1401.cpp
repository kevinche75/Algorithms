#include <iostream>
#include <cmath>

using namespace std;

int n;
int xt;
int yt;
int color = 1;
int arr[512][512];
int edge;

void rectangle(int x0, int y0, int width, int xb, int yb){
    int xc = x0 + (width -1) / 2;
    int yc = y0 + (width -1) / 2;

    if (xb <= xc && yb <= yc){
        arr[xc][yc+1] = color;
        arr[xc+1][yc+1] = color;
        arr[xc+1][yc] = color;
        color++;
        if (width > 2){
            rectangle(x0, y0, width/2, xb, yb);
            rectangle(x0, yc+1, width/2, xc, yc+1);
            rectangle(xc+1, yc+1, width/2, xc+1, yc+1);
            rectangle(xc+1, y0, width/2, xc+1, yc);
        }
        return;
    }

    if (xb <= xc && yb > yc){
        arr[xc][yc] = color;
        arr[xc+1][yc] = color;
        arr[xc+1][yc+1] = color;
        color++;
        if (width > 2){
            rectangle(x0, yc+1, width/2, xb, yb);
            rectangle(x0, y0, width/2, xc, yc);
            rectangle(xc+1, y0, width/2, xc+1, yc);
            rectangle(xc+1, yc+1, width/2, xc+1, yc+1);
        }
        return;
    }

    if (xb > xc && yb > yc){
        arr[xc+1][yc] = color;
        arr[xc][yc] = color;
        arr[xc][yc+1] = color;
        color++;
        if (width > 2){
            rectangle(xc+1, yc+1, width/2, xb, yb);
            rectangle(xc+1, y0, width/2, xc+1, yc);
            rectangle(x0, y0, width/2, xc, yc);
            rectangle(x0, yc+1, width/2, xc, yc+1);
        }
        return;
    }

    if (xb > xc && yb <= yc){
        arr[xc][yc] = color;
        arr[xc][yc+1] = color;
        arr[xc+1][yc+1] = color;
        color++;
        if (width > 2){
            rectangle(xc+1, y0, width/2, xb, yb);
            rectangle(x0, y0, width/2, xc, yc);
            rectangle(x0, yc+1, width/2, xc, yc+1);
            rectangle(xc+1, yc+1, width/2, xc+1, yc+1);
        }
    }
    return;
}


int main() {

    cin >> n >> xt >> yt;
    xt--;
    yt--;
    edge = pow(2, n);
    rectangle(0, 0, pow(2, n), xt, yt);
    for (int i = 0; i < edge; i++){
        for(int j = 0; j < edge-1; j++){
            cout << arr[i][j] << " ";
        }
        cout << arr[i][edge-1] << endl;
    }

    return 0;
}