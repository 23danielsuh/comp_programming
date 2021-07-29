#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e4 + 5;
vector<int> adj[mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    /* freopen("longpath.in", "r", stdin); */
    /* freopen("longpath.out", "w", stdout); */
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
}