#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int N, M; cin >> N >> M;
	vector<pair<int, int>> A(N); for(auto &x : A) cin >> x.first >> x.second;
	sort(A.begin(), A.end());
	vector<pair<int, int>> valid_pairs;
	for(int i = 0; i < N; i++) {
		for(int j = i; j < N; j++) {
			if(A[i].first + A[j].first > 2 * M) {
				break;
			}
			valid_pairs.push_back(make_pair(i, j));
			if(i != j) {
				valid_pairs.push_back(make_pair(j, i));
			}
		}
	}
	for(int i = 0; i <= 2 * M; i++) {
		int ans = 0;
		for(auto &x : valid_pairs) {
			if(A[x.first].first + A[x.second].first <= i && A[x.first].second + A[x.second].second >= i) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
}

