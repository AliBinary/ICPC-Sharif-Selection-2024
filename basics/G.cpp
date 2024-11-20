#include <bits/stdc++.h>

using namespace std;

#define ll long long

void playing(int a, int b, int n, vector<vector<int>> &matrix)
{
    for (int i = 0; i < n; i++)
    {
        matrix[a][i]--;
        matrix[b][i]--;
    }
}
void Main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cin >> x;
            matrix[i][x - 1] = j + 1;
        }
    }
    vector<bool> can_play_today(n);
    int day = 0;
    bool still_is_match = true;
    bool anyone_played = false;
    bool endof_turnoment = true;
    while (still_is_match)
    {
        fill(begin(can_play_today), end(can_play_today), true);

        anyone_played = false;
        endof_turnoment = true;
        for (int i = 0; i < n; i++)
        {
            if (can_play_today[i])
                for (int j = 0; j < i + 1; j++)
                {
                    if (matrix[i][j] <= 0)
                        continue;
                    endof_turnoment = false;
                    if (matrix[i][j] == 1)
                    {
                        if (matrix[j][i] == 1)
                        {
                            if (can_play_today[j])
                            {
                                anyone_played = true;
                                playing(i, j, n, matrix);
                                can_play_today[i] = false;
                                can_play_today[j] = false;
                                break;
                            }
                        }
                        else
                            break;
                    }
                }
        }

        if (endof_turnoment)
        {
            still_is_match = false;
            break;
        }
        else
            day++;

        if (anyone_played == false && still_is_match == true)
        {
            cout << -1;
            return;
        }
    }
    cout << day;
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