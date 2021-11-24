#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;
vector<int> g[mxN];
bool used[mxN];
int dp[mxN];

void dfs(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
            dp[v] += dp[u];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 0) {
            dp[i] = 1;
        }
    }
    memset(used, false, sizeof(used));
    dfs(0);
    int cnt[mxN];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cnt[dp[i]]++;
    }
    int pref[mxN];
    memset(pref, 0, sizeof(pref));
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }
    int idx = 0;
    for (int k = 1; k <= n; k++) {
        while (idx < n && pref[idx] < k) {
            idx++;
        }
        cout << idx << ' ';
    }
    cout << '\n';
}
