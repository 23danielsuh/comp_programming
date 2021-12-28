#include <bits/stdc++.h>

using namespace std;

void solve() {
	vector<int> A(3); for(auto &x : A) cin >> x;
	for(int i = 0; i < 3; i++) {
		int sum = 0;
		for(int j = 0; j < 3; j++) {
			if(i != j) {
				sum += A[j];
			}
		}
		if(sum == A[i]) {
			cout << "YES\n";
			return;
		}
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(i != j && A[i] == A[j]) {
				for(int k = 0; k < 3; k++) {
					if(i != k && j != k && A[k] % 2 == 0) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

