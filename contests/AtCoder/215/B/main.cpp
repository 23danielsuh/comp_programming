#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int cnt = 0, cur = 1;
    while(cur <= N) {
        cur <<= 1;
        cnt++;
    }
    cout << cnt - 1 << "\n";
}

