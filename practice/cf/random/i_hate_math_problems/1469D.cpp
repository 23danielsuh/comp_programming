#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double log_b(int a, int b) {
	return ceil(log(a) / log(b));
}

void solve() {
    int N; cin >> N;
	int mn_cost = INT_MAX, log_ans;
	for(int l = 2; l <= 2048; l *= 2) {
		int cost = log_b(N, l) + log2(l);
		if(cost < mn_cost) {
			mn_cost = cost;
			log_ans = l;
		}
	}
	//assert(N - 4 + mn_cost <= N + 5); //weird assertion idk
	vector<pair<int, int>> ans;
	for(int i = 1; i <= N; i++) {
		if(i != log_ans && i != 2 && i != 1 && i != N) {
			ans.push_back({i, N});
		}
	}
	for(int i = 0; i < log_b(N, log_ans); i++) {
		ans.push_back({N, log_ans});
	}
	if(log_ans != 2) {
		for(int i = 0; i < log2(log_ans); i++) {
			ans.push_back({log_ans, 2});
		}
	}
	cout << (int) ans.size() << "\n";
	for(auto &x : ans) {
		cout << x.first << " " << x.second << "\n";
	}
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

/*
 * you can just use the maximum element for a-y for all of the 1s
 * takes (n - 1) operations
 *
 * you need to get the maximum element down to 2 in 5-ish steps i think
 * log2(2*10^5) -> too big
 * log8(2*10^5)
 *
 * 16 -> 2 in 3 operations
 * max_element -> 1 in log16(max_element) operations
 *
 * 7 operations
 *
 * we only need to do the max_element operation on n - 3 elements, not including 2 and 16 and max_element
 * n - 3 + 7 -> n + 4
 *
 * 1 2 3 ... 2*10^5
 * 1  	2*10^5       X
 * 2 	2*10^5       X
 * 3  	2*10^5
 * 
 * ...
 *
 * 16   2*10^5      X
 *
 * ...
 * 
 * 2*10^5 - 1 1*10^5
 *
 * you're given a list of 2 * 10^5 - 3 1s, a 2, a 16, and a 2*10^5
 *
 * 2*10^5 / 16 -> do this ceil(log16(2*10^5)) times
 * 16 / 2 -> do this log2(16) times (4 times)
 * done
 *
 * total operations: 2 * 10^5 - 4 + ceil(log16(2*10^5)) + 4
 *
 * 3
 *
 */
