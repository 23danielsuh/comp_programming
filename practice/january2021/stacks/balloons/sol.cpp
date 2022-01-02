#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int long double

long double get_radius(int r_1, int x_1, int y_1, int x_2) {
	long double num = pow(r_1, 2LL) - pow(x_1, 2LL) + 2LL * x_1 * x_2 - pow(x_2, 2LL) - pow(y_1, 2LL);
	long double den = 2LL * (y_1 + r_1);
	return -num / den;
}

void solve() {
	cout << fixed << setprecision(10);
	int N; cin >> N;
	vector<pair<int, int>> A(N); for(auto &x : A) cin >> x.first >> x.second;
	vector<long double> ans(N);
	stack<pair<int, long double>> st;
	for(int i = 0; i < N; i++) {
		long double r = A[i].second;
		while(!st.empty()) {
			int r1 = st.top().second, x1 = st.top().first;
			//long double test = get_radius(r1, x1, r1, A[i].first);
			long double test = (x1 - A[i].first) * (x1 - A[i].first) / (4LL * r1);
			r = min(r, test);
			if(r >= r1) {
				st.pop();
			}else {
				break;
			}
		}
		st.push({A[i].first, r});
		ans[i] = r;
	}
	for(auto &x : ans) cout << x << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

