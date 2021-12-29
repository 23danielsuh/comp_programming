#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	string S; cin >> S;
	int N = (int) S.size();
	vector<pair<char, int>> last;
	map<char, int> cnt;
	for(auto &x : S) {
		cnt[x]++;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		pair<char, int> cur;
		cur = make_pair(c, INT_MAX);
		for(int i = 0; i < N; i++) {
			if(S[i] == c) {
				cur.second = i;
			}
		}
		last.push_back(cur);
	}
	sort(last.begin(), last.end(), [](const pair<char, int> &a, const pair<char, int> &b) { return a.second < b.second; });
	vector<char> orz;
	for(auto &x : last) {
		if(x.second != INT_MAX) {
			orz.push_back(x.first);
		}
	}
	int idx = 0;
	map<char, int> per_word;
	for(auto &x : orz) {
		idx++;
		if(cnt[x] % idx != 0) {
			cout << -1 << "\n";
			return;
		}
		per_word[x] = cnt[x] / idx;
	}
	idx = 0;
	for(auto &x : orz) {
		cout << x << " " << per_word[x] << "\n";
		idx++;
	}
	string ans1 = "", ans2 = "";
	for(auto &x : orz) {
		ans2 += x;
	}
	cout << ans1 << " " << ans2 << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

