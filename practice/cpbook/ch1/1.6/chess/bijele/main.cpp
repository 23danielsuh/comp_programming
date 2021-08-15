#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> A(6); for(auto &x : A) cin >> x;
    for(int i = 0; i < 6; i++) {
        if(i == 0) {
            cout << 1 - A[i];
        }else if(i == 1) {
            cout << 1 - A[i];
        }else if(i == 2) {
            cout << 2 - A[i];
        }else if(i == 3) {
            cout << 2 - A[i];
        }else if(i == 4) {
            cout << 2 - A[i];
        }else if(i == 5) {
            cout << 8 - A[i];
        }
        cout << " ";
    }
}

