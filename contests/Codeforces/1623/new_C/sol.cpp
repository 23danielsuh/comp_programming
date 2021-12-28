#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int N;
vector<int> A;

bool check(int stones) {
	vector<int> B = A;
	for(int i = N - 1; i >= 0; i--) {
		if(B[i] < stones) return false;
		int move = min(B[i] - stones, A[i]);
		int cur = move / 3;
		if(i >= 2) {
			B[i] -= cur * 3;
			B[i - 1] += cur;
			B[i - 2] += cur * 2;
		}
	}
	return true;
}

void solve() {
	cin >> N;
	A.resize(N); for(auto &x : A) cin >> x;
	int lo = 0, hi = 1e10;
	while(lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if(check(mid)) {
			lo = mid;
		}else {
			hi = mid - 1;
		}
	}
	cout << lo << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

