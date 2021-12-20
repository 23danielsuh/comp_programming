#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int findGreater(vector<int> &nums, int K) {
	int l = 0, r = (int) nums.size() - 1;
	int ret = 0;
	while(l < r) {
		if(nums[r] + nums[l] > K) {
			ret += r - l;
			if(r - l != 1) {
				ret += r - l;
			}
			r--;
		}else {
			l++;
		}
	}
	return ret;
}

int findLess(vector<int> &nums, int K) {
	int l = 0, r = (int) nums.size() - 1;
	int ret = 0;
	while(l < r) {
		if(nums[r] + nums[l] < K) {
			ret += r - l;
			r--;
		}else {
			l++;
		}
	}
	return ret;
}

void solve() {
	int N, M; cin >> N >> M;
	vector<int> A(N), B(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	for(int i = 0; i <= 2 * M; i++) {
		int pos = N * N - findLess(A, i) - findGreater(B, i) - ;
		cout << pos << "\n";
	}
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
}

