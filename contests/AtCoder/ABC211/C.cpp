#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int MOD = 1e9 + 7;

int count(string a, string b)
{
    int m = a.length();
    int n = b.length();
 
    vector<vector<int>> lookup(m + 1);
    for(auto &x : lookup) {
        x.resize(n + 1);
    }
 
    for (int i = 0; i <= n; ++i)
        lookup[0][i] = 0;
 
    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + lookup[i - 1][j];
                lookup[i][j] %= MOD;
            } else {
                lookup[i][j] = lookup[i - 1][j];
                lookup[i][j] %= MOD;
            }
        }
    }
 
    return lookup[m][n] % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string sub = "chokudai", S; cin >> S;
    cout << count(S, sub);
}
