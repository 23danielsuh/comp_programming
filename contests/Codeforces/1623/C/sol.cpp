#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

bool check(vector<int> A, int &N, int stones) {
	for(int i = 0; i < N - 1; i++) {
		for(auto &x : A) cout << x << " ";
		cout << "\n";
		if(A[i] < stones) {
			if(i + 2 >= N) {
				int cur = A[i + 1];
				int give = cur / 3;
				if(A[i] + give >= stones) {
					A[i] += A[i + 1] / 3;
					A[i - 1] += (A[i + 1] / 3) * 2;
					A[i + 1] -= (A[i + 1] / 3) * 3;
				}else {
					return false;
				}
			}
			int cur = A[i + 2];
			int give = cur / 3 * 2;
			if(A[i] + give >= stones) {
				A[i + 1] += A[i + 2] / 3;
				A[i] += (A[i + 1] / 3) * 2;
				A[i + 2] -= (A[i + 2] / 3) * 3;
			}else {
				A[i + 1] += A[i + 2] / 3;
				A[i] += (A[i + 1] / 3) * 2;
				A[i + 2] -= (A[i + 2] / 3) * 3;
				if(i > 0) {
					cur = A[i + 1];
					give = cur / 3;
					if(A[i] + give >= stones) {
						A[i] += A[i + 1] / 3;
						A[i - 1] += (A[i + 1] / 3) * 2;
						A[i + 1] -= (A[i + 1] / 3) * 3;
					}else {
						return false;
					}
				}else {
					return false;
				}
			}
		}
	}
	for(int i = 0; i < N; i++) {
		if(A[i] < stones) {
			return false;
		}
	}
	return true;
}

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	int lo = 0, hi = 1e9;
	while(lo < hi) {
		int mid = (lo + hi + 1) / 2;
		cout << mid << "\n";
		if(check(A, N, mid)) {
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

