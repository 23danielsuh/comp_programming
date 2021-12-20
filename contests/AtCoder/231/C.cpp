#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll

typedef tree<long long, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

void solve() {
    int N, Q; cin >> N >> Q;
    indexed_multiset ms;
    for(int i = 0; i < N; i++) {
	    int x; cin >> x;
	    ms.insert(x);
    }
    while(Q--) {
	    int x; cin >> x;
	    cout << N - ms.order_of_key(x) << "\n";
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

