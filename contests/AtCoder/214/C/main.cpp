#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> S(N), T(N); 
    for(auto &x : S) cin >> x;
    for(auto &x : T) cin >> x;
    int mn = *min_element(T.begin(), T.end()), ind = 0;
    for(int i = 0; i < N; i++) {
        if(T[i] == mn) {
            ind = i;
        }
    }
    int cur = mn;
    vector<int> ans(N, INT_MAX);
    ans[ind] = mn;
    ind++;
    ind %= N;
    while(true) {
        int pos1, pos2 = T[ind];
        if(ind == 0) {
            pos1 = S[N - 1] + cur;
        }else {
            pos1 = S[ind - 1] + cur;
        }

        int temp = min(pos1, pos2);
        if(temp >= ans[ind]) {
            break;
        }
        ans[ind] = min(pos1, pos2);
        cur = min(pos1, pos2);

        ind++;
        ind %= N;
    }
    for(auto &x : ans) cout << x << "\n";
}

