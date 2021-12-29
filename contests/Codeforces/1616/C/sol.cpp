#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cost(vector<int> &A) {
	if(A.size() < 3) return 0;
	int N = (int) A.size();
	int minCost = N;
	for(int i = 0; i < N - 1; i++) {
		for(int j = i + 1; j < N; j++) {
			double delta = (double) (A[j] - A[i]) / (j - i);
			int cost = 0;
			for(int k = 0; k < N; k++) {
				if(k == i) continue;
				if((A[k] + delta * (i - k)) != A[i]) { cost++; }
			}
			minCost = min(minCost, cost);
		}
	}
	return minCost;
}

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	if(N == 1) {
		cout << 0 << "\n";
		return;
	}
	cout << cost(A) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

