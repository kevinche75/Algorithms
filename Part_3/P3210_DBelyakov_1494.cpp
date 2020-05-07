#include "iostream"
#include "stack"

using namespace std;


int main(){
    long n, tmp, tmp_max;
    stack<int> residuals;
    cin >> n;
    bool flag = true;
    tmp_max = 0;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        if (tmp > tmp_max){
            for(int j = tmp_max + 1; j < tmp; j ++){
                residuals.push(j);
            }
            tmp_max = tmp;
        }
        else if(tmp == residuals.top()) residuals.pop(); else flag = false;
    }
    if (flag) cout << "Not a proof"; else cout << "Cheater";
    return 0;
}