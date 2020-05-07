#include <iostream>

using namespace std;

int main() {

    int number;
    cin >> number;

    for (int i = 0; i < number; ++i)	{
        int n,  k;
        cin >> n >> k;
        int casualGroup = n / k;
        int numberExtinctGroup = n % k;
        int extinctGroup = casualGroup + 1;

        cout << ((n - numberExtinctGroup * extinctGroup)*(n - casualGroup) + (numberExtinctGroup * extinctGroup)*(n - extinctGroup))/2 << endl;
    }

    return 0;
}