#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, a, b; cin >> N >> a >> b;
	vector<int> A(N); for(auto &x : A) cin >> x;
	multiset<int> sw;
	ll ans = 0, sum = 0; int cur_size = 0;
	for(int i = 0; i < a; i++) {
		sw.insert(A[i]); sum += A[i];
		cur_size++;
	}
	for(int i = a; i <= N; i++) {
		while(cur_size > b) {
			sw.erase(sw.find(A[i - cur_size]));
			sum -= A[i - cur_size];
			cur_size--;
		}
		assert(cur_size >= a && cur_size <= b);
		while(cur_size > a && sw.size() && A[i - cur_size] <= 0) {
			sw.erase(sw.find(A[i - cur_size]));
			sum -= A[i - cur_size];
			cur_size--;
		}
		cout << cur_size << ": ";
		for(auto &x : sw) cout << x << " ";
		cout << "-> " << sum << "\n";
		ans = max(ans, sum);
		if(i == N) break;
		sum += A[i];
		cur_size++;
		sw.insert(A[i]);
	}
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

//you can choose to erase the beginning element or not
//you delete the first element only if the size exceeds b, or if the number is negative
