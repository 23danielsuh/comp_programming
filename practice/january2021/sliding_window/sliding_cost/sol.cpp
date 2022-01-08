#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef tree<long long, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N); for(auto &x : A) cin >> x;
	indexed_multiset sw;
	for(int i = 0; i < K; i++) {
		sw.insert(A[i]);
	}
	cout << *sw.find_by_order((K - 1) / 2) << " ";
	for(int i = K; i < N; i++) {
		sw.erase(--sw.lower_bound(A[i - K]));
		sw.insert(A[i]);
		cout << *sw.find_by_order((K - 1) / 2) << " ";
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

