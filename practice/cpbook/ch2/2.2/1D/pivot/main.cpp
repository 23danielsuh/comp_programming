#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N); for(auto &x : A) cin >> x;
    vector<int> pre_max(N + 1, INT_MIN), post_min(N + 1, INT_MAX);
    for(int i = 0; i < N; i++) {
        pre_max[i + 1] = max(pre_max[i], A[i]);
    }
    for(int i = N; i > 0; i--) {
        post_min[i - 1] = min(post_min[i], A[i - 1]);
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(pre_max[i] < A[i] && post_min[i + 1] > A[i]) {
            ans++;
        }
    }
    cout << ans << "\n";
}

