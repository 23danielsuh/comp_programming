#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
#define int ll

typedef tree<long long, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

void solve() {
    int N; cin >> N;
    indexed_multiset cur;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        int left = cur.order_of_key(x); //num elements strictly less than x
        int right = i - cur.order_of_key(x + 1); //num elemens strictly greater than x
        ans += min(left, right);
        cur.insert(x);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

