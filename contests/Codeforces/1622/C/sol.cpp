#include <bits/stdc++.h>

using namespace std;
#define int int64_t

vector<int> psum;
vector<int> A;
int sum = 0, ans = 0;
int N, K;

bool check(int e, int x) {
	return sum - (psum[N] - psum[N - e]) + e * x - A[0] + x <= K;
}

void solve() {
	cin >> N >> K;
	A.resize(N);
	sum = 0, ans = 0;
	for(auto &x : A) {
		cin >> x;
		sum += x;
	}
	if(sum <= K) {
		cout << 0 << "\n";
		return;
	}
	ans = sum;
	sort(A.begin(), A.end());
	int storeA = A[0];
	ans = min(ans, storeA + N - 1);
	psum.resize(N + 1);
	for(int i = 0; i < N; i++) {
		psum[i + 1] = psum[i] + A[i];
	}
	for(int x = K;; x--) {
		//decrement until you take all N - 1 elements
		//binary search on e, and if e is ever equal to N - 1, then you break
		int l = 0, r = N;
		bool pos = 0;
		while(l < r) {
			int mid = (l + r) / 2;
			if(check(mid, x)) {
				r = mid;
				pos = 1;
			}else {
				l = mid + 1;
			}
		}
		if(pos) {
			ans = min(ans, r + (storeA - x));
		}
		if(x <= -10) { //arbitrary break idk lol
			break;
		}
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

