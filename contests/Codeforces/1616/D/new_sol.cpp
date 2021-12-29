#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	int X; cin >> X;
	vector<int> psum(N + 1);
	for(int i = 0; i < N; i++) {
		psum[i + 1] = psum[i] + A[i];
	}
	int r = 2;
	//1-indexed
	vector<int> border(N);
	for(int i = 0; i < N; i++) {
		//r = max(r, i + 2);
		r = i + 2;
		while(r < N && psum[r] - psum[i] >= (min(r - 1, N - 1) - i + 1) * X) {
			r++;
		}
		r--;
		cout << i << " -> " << r << "\n";
		border[i] = min(r, N);
		cout << "the sum in the range of [" << min(r, N - 1) << ", " << i << "]: " << psum[min(r, N - 1)] - psum[i] << "\n";
		if(psum[min(r, N - 1)] - psum[i] < (min(r - 1, N - 1) - i + 1) * X) {
			border[i] = -1;
		}
	}
	for(auto &x : border) cout << x << " ";
	cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

