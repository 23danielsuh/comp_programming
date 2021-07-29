#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<int, int> find_slope(int a, int b) {
    if(a == 0) {
        return make_pair(0, 0);
    }else if(b == 0) {
        return make_pair(INT_MAX, INT_MAX);
    }
    return (make_pair(a / gcd(a, b), b / gcd(a, b)));
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int N; string S; cin >> N >> S;
        pair<int, int> prev = {0, 0};
        map<pair<int, int>, int> cnt;
        for(int i = 0; i < N; i++) {
            if(S[i] == 'D') {
                prev.first++;
            }else {
                prev.second++;
            }
            pair<int, int> slope = find_slope(prev.first, prev.second);
            cout << ++cnt[slope] << " ";
        }
        cout << "\n";
    }
}

