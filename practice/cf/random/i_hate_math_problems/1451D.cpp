#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
	int d, k; cin >> d >> k;
	int x = 0, y = 0;
	while(true) {
		if(x <= y && (x + k) * (x + k) + y * y <= d * d) {
			x += k;
		}else if(x > y && (y + k) * (y + k) + x * x <= d * d) {
			y += k;
		}else {
			break;
		}
	}
	if(x == y) {
		cout << "Utkarsh\n";
	}else {
		cout << "Ashish\n";
	}
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

/*
 * what is optimal for A and what is optimal for U?
 * i think that A can win in all circumstances except for when:
 * can you arrive in one of the "outer" border squares in % 2 moves?
 */
