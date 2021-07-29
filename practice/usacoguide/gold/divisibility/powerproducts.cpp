#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int N, K;

vector<pair<int, int>> prime_factor(int a) {
    map<int, int> cnt;
    for(int i = 2; i * i <= a; i++) {
        while(a % i == 0) {
            a /= i;
            cnt[i]++;
        }
    }
    if(a > 1) {
        cnt[a]++;
    }
    vector<pair<int, int>> ret;
    for(auto &x : cnt) {
        if((x.second % K) != 0) {
            ret.push_back({x.first, x.second % K});
        }
    }
    return ret;
}

vector<pair<int, int>> inv(vector<pair<int, int>> cur) {
    vector<pair<int, int>> ret;
    for(int i = 0; i < (int) cur.size(); i++) {
        assert(cur[i].second < K);
        ret.push_back({cur[i].first, K - cur[i].second});
    }
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    vector<int> A(N); for(auto &x : A) cin >> x;
    map<vector<pair<int, int>>, int> cnt;
    for(int i = 0; i < N; i++) {
        cnt[prime_factor(A[i])]++;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        vector<pair<int, int>> bases = prime_factor(A[i]);
        vector<pair<int, int>> rev_base = inv(bases);
        if(bases == rev_base) {
            ans += cnt[bases] - 1;
        }else {
            ans += cnt[rev_base];
        }
    }
    cout << ans / 2 << "\n";
}
