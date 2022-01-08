#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N); for(auto &x : A) cin >> x;
	multiset<int> sw;
	for(int i = 0; i < K; i++) {
		sw.insert(A[i]);
	}
	auto it = sw.begin();
	for(int i = 0; i < (K + 1) / 2 - 1; i++) {
		it++;
	}
	vector<int> ans;
	ans.push_back(*it);
	for(int i = K; i < N; i++) {
		int l = A[i - K], r = A[i];
		if(l == *it) {
			cout << "CASE 1: ";
			sw.erase(sw.find(l));
			sw.insert(r);
			if(r > *it) {
				it++;
			}else {
				it--;
			}
			ans.push_back(*it);
			for(auto &x : sw) cout << x << " ";
			cout << " -> " << *it << "\n";
			continue;
		}
		if(r == *it) {
			cout << "CASE 2: ";
			if(r > *it) {
				it++;
			}else {
				it--;
			}
			sw.erase(sw.find(l));
			sw.insert(r);
			ans.push_back(*it);
			for(auto &x : sw) cout << x << " ";
			cout << " -> " << *it << "\n";
			continue;
		}
		if((l <= *it && r <= *it) || (l > *it && r > *it)) {
			cout << "CASE 3: ";
			sw.erase(sw.find(l));
			sw.insert(r);
		}else if(l < *it && r > *it) {
			cout << "CASE 4: ";
			sw.erase(sw.find(l));
			sw.insert(r);
			it++;
		}else {
			cout << "CASE 5: ";
			sw.erase(sw.find(l));
			sw.insert(r);
			it--;
		}
		ans.push_back(*it);
		for(auto &x : sw) cout << x << " ";
		cout << " -> " << *it << "\n";
	}
	for(auto &x : ans) cout << x << " ";
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

