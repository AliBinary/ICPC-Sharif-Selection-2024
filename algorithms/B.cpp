#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

void Main()
{
    int n;
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c > d)
        swap(c, d);
    if (a > b)
        swap(a, b);

    if (c < a && d > a && d < b)
        cout << 4;
    else if (c > a && c < b && d > b)
        cout << 4;
    else
        cout << 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        Main();
    return 0;
}