#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> A, cnt;

bool check(int x) {
    for (int i = 1; i <= N; i ++) cnt[i] = 0;
    for (int i = 0; i < N; i ++) cnt[A[i]]++;

    set<pair<int, int>, greater<pair<int, int>>> ss; //use greater comparator to sort set in descending order
    for (int i = 1; i <= N; i ++) {
        if (cnt[i] > 0) ss.insert({cnt[i], i});
    }

    vector<int> b;
    for (int i = 0; i < N; i ++) {
        if (i >= x && cnt[b[i - x]]) {
            ss.insert({cnt[b[i - x]], b[i - x]});
        }

        if (ss.empty()) return 0;
        b.push_back(ss.begin()->second);
        ss.erase(ss.begin());
        cnt[b.back()]--;
    }

    return 1;
}

int bin_search() {
    int lo = 0, hi = N + 100;
    while(lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if(check(mid)) {
            lo = mid;
        }else {
            hi = mid - 1;
        }
    }
    return lo - 1;
}

void solve() {
    cin >> N;
    A.clear(); cnt.clear();
    A.resize(N); for(auto &x : A) cin >> x;
    cnt.resize(N + 1); for(auto &x : A) cnt[x]++;
    cout << bin_search() << "\n";
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
