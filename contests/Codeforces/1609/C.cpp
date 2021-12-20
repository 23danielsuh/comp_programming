#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int int64_t

const int mxN = 1e7, mxNN = 1e7 + 5;
vector<bool> is_prime(mxNN, true);

void sieve() {
    for (int i = 2; i <= mxN; i++) {
        if (is_prime[i] && (long long)i * i <= mxN) {
            for (int j = i * i; j <= mxN; j += i)
                is_prime[j] = false;
        }
    }
}

void solve() {
    map<int, vector<int>> lb;
    map<int, vector<int>> prime_indices;
    int N, E; cin >> N >> E;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        lb[i % E].push_back(i);
        if(is_prime[A[i]]) prime_indices[i % E].push_back(i / E);
    }
    
    int sum = 0;

    map<int, vector<int>> primes_after;
    for(auto &x : lb) {
        vector<int> cur;
        for(int i = 0; i < (int) x.second.size(); i++) {
            if(is_prime[A[x.second[i]]]) {
                int cnt = 0, j = i + 1;
                while(j < (int) x.second.size() && A[x.second[j]] == 1) {
                    j++;
                    cnt++;
                }
                cur.push_back(cnt);
                for(int k = 0; k < cnt; k++) {
                    cur.push_back(0);
                }
                i = j - 1;
            }else {
                cur.push_back(0);
            }
        }
        primes_after[x.first] = cur;
    }
    
    for(auto &x : lb) {
        vector<int> cur = x.second;
        int M = (int) cur.size();
        for(int i = 0; i < M; i++) {
            if(A[cur[i]] == 1) {
                auto it = upper_bound(prime_indices[x.first].begin(), prime_indices[x.first].end(), i);
                if(it == prime_indices[x.first].end()) {
                    continue;
                }
                sum += primes_after[x.first][*it] + 1;
                continue;
            }
            if(is_prime[A[cur[i]]]) {
                sum += primes_after[x.first][i];
            }
        }
    }
    
    cout << sum << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    is_prime[0] = is_prime[1] = false;
    sieve();
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

