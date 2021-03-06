#include <bits/stdc++.h>
using namespace std;

const int INF = 2000000000;

const int MAXN = 100005;
int color[MAXN], xmin[MAXN], xmax[MAXN], inStack[MAXN];

int n;

vector<int> st;

int main() {
    scanf("%d", &n);

    fill(xmin, xmin + MAXN, INF);
    fill(xmax, xmax + MAXN, -INF);

    color[0] = color[n+1] = 0;

    for (int i = 0; i <= n+1; i++) {
        if (i >= 1 && i <= n) scanf("%d", &color[i]);
        xmin[color[i]] = min(xmin[color[i]], i);
        xmax[color[i]] = max(xmax[color[i]], i);
    }

    int res = 0;  // max depth

    for (int i = 0; i <= n+1; i++) {
        int c = color[i];

        if (i == xmin[c]) {
            st.push_back(c);
            res = max(res, (int)st.size());
        }

        if (st[st.size()-1] != c) {
            cout << -1 << "\n";
            return 0;
        }

        if (i == xmax[c]) {
            st.pop_back();
        }
    }

    cout << res - 1 << "\n";
    return 0;
}
