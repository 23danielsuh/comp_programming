#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int N, K, X = 0;
vector<vector<int>> adj;
vector<int> A, subtree_xor, dist;

int compute_xor(int s, int prev = -1) {
    int cur = A[s];
    for(auto &x : adj[s]) {
        if(x != prev) {
            cur ^= compute_xor(x, s);
        }
    }
    subtree_xor[s] = cur;
    return cur;
}

void find_dist() {
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &x : adj[cur]) {
            if(dist[cur] + 1 < dist[x]) {
                q.push(x);
                dist[x] = dist[cur] + 1;
            }
        }
    }
}

int deepest = INT_MIN; pair<int, int> rem;

void find_edge(int s, int prev = -1) {
    if(prev != -1 && subtree_xor[s] == X && dist[s] > deepest) {
        deepest = dist[s];
        rem = {prev, s};
    }
    for(auto &x : adj[s]) {
        if(x != prev) {
            find_edge(x, s);
        }
    }
}

void erase_edge() {
    for(int i = 0; i < (int) adj[rem.first].size(); i++) {
        if(adj[rem.first][i] == rem.second) {
            adj[rem.first].erase(adj[rem.first].begin() + i);
        }
    }
    for(int i = 0; i < (int) adj[rem.second].size(); i++) {
        if(adj[rem.second][i] == rem.first) {
            adj[rem.second].erase(adj[rem.second].begin() + i);
        }
    }
}

void print_adj() {
    for(int i = 0; i < N; i++) {
        cout << i << " IS CONNECTED TO: ";
        for(auto &x : adj[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

void solve() {
    X = 0;
    cin >> N >> K;
    A.resize(N); for(auto &x : A) cin >> x;
    subtree_xor.clear(); subtree_xor.resize(N);
    dist.clear(); dist.resize(N); fill(dist.begin(), dist.end(), INT_MAX);
    deepest = INT_MIN; rem = {0, 0};
    K--;
    for(auto &x : A) X ^= x;
    adj.clear(); adj.resize(N);
    for(int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(X == 0) {
        cout << "YES\n";
        return;
    }
    compute_xor(0);
    find_dist();
    find_edge(0);
    if(deepest == INT_MIN) {
        cout << "NO\n";
        return;
    }
    deepest = INT_MIN;
    erase_edge();
    subtree_xor.clear(); subtree_xor.resize(N);
    compute_xor(0);
    find_edge(0);
    if(deepest == INT_MIN) {
        cout << "NO\n";
        return;
    }
    if(K == 1) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

