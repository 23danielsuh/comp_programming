#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N); for(auto &x : A) cin >> x;
    int a = 1, b = A[0];
    cout << "\n";
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            cout << lcm(A[i], A[j]) << "\n";
        }
    }
}
