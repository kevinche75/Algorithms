#include <iostream>
#include <algorithm>

using namespace std;
long long n, x[100005], y[100005], sum=0;

int main()
{
    cin >> n;
    for (long i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    sort(&x[0], &x[n]);
    sort(&y[0], &y[n]);

    for (long i=1; i<n; i++)
    {
        sum += (x[i] - x[i - 1]) * i * (n - i) * 2;
        sum += (y[i] - y[i - 1]) * i * (n - i) * 2;
    }

    cout << (sum) / (n*(n - 1));
    return 0;
}