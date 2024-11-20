#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

void Main()
{
    ll n;
    cin >> n;
    string s1;
    cin >> s1;
    vector<ll> A(n);
    for (auto &x : A)
    {
        cin >> x;
    }
    vector<ll> net;
    for (auto &ch : s1)
    {
        if (ch == 'X')
        {
            net.push_back(A.front());
            A.erase(A.begin());
        }
        else if (ch == 'A')
        {
            net.push_back(-1);
        }
        else if (ch == 'B')
        {
            net.push_back(-2);
        }
    }

    // for (auto &x : net)
    // {
    //     cout << x << ' ';
    // }
    while (net.size() > 1)
    {
        while (1)
        {
            bool flag = true;
            for (int i = net.size() - 3; i >= 0; i--)
            {
                if (net[i] == -1)
                    if (net[i + 1] > -1 && net[i + 2] > -1)
                    {
                        flag = false;
                        net[i] = (net[i + 1] + net[i + 2]);
                        net.erase(net.begin() + i + 1);
                        net.erase(net.begin() + i + 1);
                        break;
                    }
            }
            if (flag)
                break;
        }
        for (int i = net.size() - 3; i >= 0; i--)
        {
            if (net[i] == -2)
            {
                net[i] = max(net[i + 1], net[i + 2]);
                net.erase(net.begin() + i + 1);
                net.erase(net.begin() + i + 1);
                break;
            }
        }
    }
    cout << net[0];
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