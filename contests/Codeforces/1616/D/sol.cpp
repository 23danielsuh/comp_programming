#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	int X; cin >> X;
	int ans = 0;
	for(int i = 0; i < N - 1; i++) {
		int sum = A[i] + A[i + 1];
		int j = i + 1;
		while(j < N && sum >= X * (j - i + 1)) {
			j++;
			if(j < N) {
				sum += A[j];
			}
		}
		cout << i << " -> " << j << "\n";
		ans += (j - i);
		i = j;
		//cout << i << " " << j << "\n";
	}
	cout << ans << "\n";
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

