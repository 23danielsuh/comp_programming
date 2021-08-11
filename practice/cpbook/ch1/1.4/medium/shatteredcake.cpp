#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int W, N; cin >> W >> N;
    vector<pair<int, int>> A(N); 
    int area = 0;
    for(auto &x : A) {
        cin >> x.first >> x.second;
        area += x.first * x.second;
    }
    for(int i = 0; i <= 10000; i++) {
        if(W * i == area) {
            cout << i << "\n";
            break;
        }
    }
}

