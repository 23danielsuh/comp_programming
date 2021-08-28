#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 4e5 + 5;
int dif[mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<int, int>> A(N);
    set<int> coordcomp_x;
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        coordcomp_x.insert(A[i].first);
        coordcomp_x.insert(A[i].second + 1);
    }
    int it = 0;
    map<int, int> vals_x;
    vector<int> coords;
    for(auto &x : coordcomp_x) {
        vals_x[x] = it;
        
        coords.push_back(x);
        it++;
    }
    for(auto &x : A) {
        dif[vals_x[x.first]]++;
        dif[vals_x[x.second + 1]]--;
    }
    for(int i = 1; i < mxN; i++) {
        dif[i] += dif[i - 1];
    }
    map<int, int> ans;
    for(int i = 1; i < (int) coords.size(); i++) {
        ans[dif[i - 1]] += coords[i] - coords[i - 1];
    }
    for(int k = 1; k <= N; k++) {
        cout << ans[k] << " ";
    }
}

