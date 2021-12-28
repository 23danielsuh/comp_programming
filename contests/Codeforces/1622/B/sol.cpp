#include <bits/stdc++.h>

using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N);
	int ones = 0, zeros = 0;
	vector<pair<int, int>> one_vec, z_vec;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	string S; cin >> S;
	for(int i = 0; i < N; i++) {
		if(S[i] == '1') {
			ones++;
			one_vec.push_back({A[i], i});
		}else {
			zeros++;
			z_vec.push_back({A[i], i});
		}
	}
	vector<int> last_elements, first_elements;
	for(int i = N - ones + 1; i <= N; i++) {
		last_elements.push_back(i);
	}
	for(int i = 1; i <= N - ones; i++) {
		first_elements.push_back(i);
	}
	sort(one_vec.begin(), one_vec.end());
	sort(z_vec.begin(), z_vec.end());
	vector<int> ans(N);
	for(int i = 0; i < (int) last_elements.size(); i++) {
		ans[one_vec[i].second] = last_elements[i];
	}
	for(int i = 0; i < (int) first_elements.size(); i++) {
		ans[z_vec[i].second] = first_elements[i];
	}
	for(auto &x : ans) cout << x << " ";
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

