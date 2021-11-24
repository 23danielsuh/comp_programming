#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int N, K;

vector<int> heads(vector<int> Q, vector<int> P) {
    vector<int> new_P(N + 1);
    for(int i = 1; i <= N; i++) {
        new_P[i] = P[Q[i]];
    }
    return new_P;
}

vector<int> tails(vector<int> Q, vector<int> P) {
    vector<int> new_P(N + 1);
    for(int i = 1; i <= N; i++) {
        int idx = 0;
        for(int j = 1; j <= N; j++) {
            if(Q[j] == i) {
                idx = j;
                break;
            }
        }
        new_P[i] = P[idx];
    }
    return new_P;
}

void solve() {
    cin >> N >> K;
    vector<int> Q(N + 1); 
    for(int i = 1; i <= N; i++) {
        cin >> Q[i];
    }
    vector<int> S(N + 1); 
    for(int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    vector<int> P(N + 1);
    for(int i = 1; i <= N; i++) {
        P[i] = i;
    }
    vector<int> inv = tails(Q, P);
    if(Q == inv) {
        if(K == 1) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
        return;
    }
    vector<int> valid_heads;
    vector<int> cur = P;
    for(int i = 1; i <= K; i++) {
        cur = heads(Q, cur);
        bool flag = 0;
        for(int j = 1; j <= N; j++) {
            if(cur[j] != S[j]) {
                flag = 1;
            }
        }
        if(!flag) {
            valid_heads.push_back(i);
            if(K == i) {
                cout << "YES\n";
                return;
            }
        }
    }
    cur = P;
    vector<int> valid_tails;
    for(int i = 1; i <= K; i++) {
        cur = tails(Q, cur);
        bool flag = 0;
        for(int j = 1; j <= N; j++) {
            if(cur[j] != S[j]) {
                flag = 1;
            }
        }
        if(!flag) {
            if(K == i) {
                valid_tails.push_back(i);
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
