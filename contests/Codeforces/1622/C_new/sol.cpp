#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int N, K, sum = 0; 
vector<int> A;

bool check(int steps) {
	
}

void solve() {
	cin >> N >> K;
	A.resize(N);
	sum = 0;
	for(auto &x : A) {
		cin >> x;
		sum += x;
	}
	sort(A.begin(), A.end());
	int lo = 0, hi = 1e18 + 5;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		if(check(mid)) {
			hi = mid;
		}else {
			lo = mid + 1;
		}
	}
	cout << lo << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

