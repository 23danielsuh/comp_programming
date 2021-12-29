#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; 
	string S;
	cin >> N >> S;
	if(N == 1) {
		cout << S << S << "\n";
		return;
	}
	string ans = "";
	//special case:
	if(S[0] <= S[1]) {
		cout << S[0] << S[0] << "\n";
		return;
	}
	for(int i = 0; i < N; i++) {
		if(i > 0) {
			if(S[i] > S[i - 1]) {
				break;
			}
			ans += S[i];
		}else {
			ans += S[i];
		}
	}
	cout << ans;
	reverse(ans.begin(), ans.end());
	cout << ans;
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

