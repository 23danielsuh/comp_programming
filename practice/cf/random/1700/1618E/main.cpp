#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int N; cin >> N;
    vector<int> B(N); 
    int sum_B = 0;
    for(auto &x : B) {
        cin >> x;
        sum_B += x;
    }
	if(N == 1) {
		cout << "YES\n";
		cout << B[0] << "\n";
		return;
	}
    vector<int> A(N);
    if(sum_B % (N * (N + 1) / 2) != 0) {
        cout << "NO\n";
        return;
    }
    int sum_A = (sum_B) / (N * (N + 1) / 2);
    for(int i = 0; i < N; i++) {
        int j = i - 1;
        if(i == 0) {
            j = N - 1;
        }
        if(sum_A - B[i] + B[j] > 0 && (sum_A - B[i] + B[j]) % N == 0) {
            A[i] = (sum_A - B[i] + B[j]) / N;
        }else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(auto &x : A) {
        cout << x << " ";
    }
    cout << "\n";
}

void floodfill(int r, int c) {
	
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
