#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void solve() {
    int N, D; cin >> N >> D;
    vector<int> A(N); for(auto &x : A) cin >> x;
    vector<vector<int>> con_comp;
    vector<int> swaps(N); vector<bool> visited(N);
    for(int i = 0; i < N; i++) {
        swaps[(i + D) % N] = i;
    }
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            int first = i, idx = swaps[i];
            vector<int> temp;
            temp.push_back(first);
            while(idx != first) {
                temp.push_back(idx); 
                visited[idx] = true;
                idx = swaps[idx];
            }
            //sort(temp.begin(), temp.end());
            reverse(temp.begin() + 1, temp.end());
            con_comp.push_back(temp);
        }
    }
    for(auto &x : con_comp) {
        bool ok = 0;
        for(auto &y : x) {
            if(A[y] == 0) {
                ok = 1;
            }
        }
        if(!ok) {
            cout << -1 << "\n";;
            return;
        }
    }
    int mx_steps = 0;
    for(auto &x : con_comp) {
        int M = (int) x.size();
        //0 -> 2 -> 4 -> 1 -> 3 -> 0
        //0 -> 4 takes 2 steps
        //0 -> 3 takes 4 steps
        //
        //keep track of where all of the 0s are. How do we find the nearest 0 to node i?
        set<int> indices;
        for(int i = 0; i < M; i++) {
            if(A[x[i]] == 0) {
                indices.insert(i);
            }
        }
        indices.insert(INT_MAX);
        int l = *indices.begin();
        for(int i = 0; i < M; i++) {
            if(A[x[i]] == 1) {
                int r = *indices.lower_bound(i);
                int steps = min(r - i, M - i + l);
                mx_steps = max(mx_steps, steps);
            }
        }
    }
    cout << mx_steps << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
