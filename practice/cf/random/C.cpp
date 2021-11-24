#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for(auto &x : A) cin >> x;
    if(is_sorted(A.begin(), A.end())) {
        cout << "yes\n";
        cout << "1 1\n";
        return;
    }
    vector<int> rev;
    bool flag = 0;
    for(int i = 0; i < N - 1; i++) {
        bool temp = 0;
        while(!flag && i < N - 1 && A[i] > A[i + 1]) {
            temp = 1;
            rev.push_back(i);
            i++;
        }
        if(temp) {
            rev.push_back(i);
            flag = 1;
        }
    }
    reverse(A.begin() + *rev.begin(), A.begin() + *rev.rbegin() + 1);
    if(is_sorted(A.begin(), A.end())) {
        cout << "yes\n";
        cout << *rev.begin() + 1  << " " << *rev.rbegin() + 1 << "\n";
    }else {
        cout << "no\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

