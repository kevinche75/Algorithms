#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct cha{
    char c;
    int index;
};

int main() {
    string str;
    int row_number;
    cha count[100001];
    cin >> row_number;
    cin >> str;

    row_number --;
    int str_size = str.length();
    for(int i=0;i<str_size;i++){
        count[i].c = str[i];
        count[i].index = i;
    }

    sort(&count[0], &count[str_size], [](const cha a, const cha b)->bool {
        if(a.c != b.c){
            return a.c < b.c;
        }
        return a.index < b.index;
    });
    cout << row_number << " ";
    for (int i = 0; i< str_size; i ++){
        cout << count[row_number].c;
        row_number = count[row_number].index;
        cout << row_number << " ";
    }

    return 0;
}