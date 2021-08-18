#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    vector<int> squares;
    for(int i = 0; i < sqrt((int) 1e10); i++) {
        squares.push_back(i * i);
    }
    while(T--) {
        int n; cin >> n;
        auto it = lower_bound(squares.begin(), squares.end(), n);
        int row = it - squares.begin();
        int sub = *it - n + 1;
        if(sub <= sqrt(*it)) {
            cout << row << " " << sub << "\n";
        }else {
            int new_row = row - (sub - sqrt(*it));
            cout << new_row << " " << sqrt(*it) << "\n";
        }
    }
}

