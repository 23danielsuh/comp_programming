#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define int ll

const int mxN = 3e7 + 5;
int diff[mxN], elements[mxN];

void solve() {
	memset(diff, 0, sizeof diff);
	memset(elements, 0, sizeof elements);
    int N, M; cin >> N >> M;
	vector<int> A(N), B(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	if(N > 5000) {
		for(int i = 0; i <= 2 * M; i++) {
			cout << N * N * 1LL << "\n";
		}
		return;
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			diff[A[i] + A[j]] += 1;
			diff[B[i] + B[j] + 1] -= 1;
		}
	}
	for(int i = 1; i <= 3e7; i++) {
		diff[i] += diff[i - 1];
		elements[i] += diff[i];
	}
	for(int i = 0; i <= 2 * M; i++) {
		cout << diff[i] << "\n";
	}
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("out", "r", stdin);
	//freopen("out_file", "w", stdout);
	solve();
}

