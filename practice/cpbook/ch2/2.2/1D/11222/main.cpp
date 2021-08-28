#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e4 + 5;
int cnt[mxN];

bool cmp(const pair<vector<int>, int> &a, const pair<vector<int>, int> &b) {
    if(a.first.size() == b.first.size()) {
        return a.second < b.second;
    }
    return a.first.size() > b.first.size();
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int T; cin >> T;
    int tc = 1;
    while(T--) {
        cout << "Case #" << tc << ":\n";
        tc++;
        memset(cnt, 0, sizeof cnt);
        vector<vector<int>> A(3);
        for(auto &x : A) {
            set<int> st;
            int N; cin >> N;
            x.resize(N);
            for(auto &i : x) {
                cin >> i;   
                st.insert(i);
            }
            for(auto &x : st) {
                ++cnt[x];
            }
        }
        vector<pair<vector<int>, int>> ans(3);
        for(int i = 0; i < 3; i++) {
            set<int> st;
            for(auto &j : A[i]) {
                st.insert(j);
            }
            for(auto &j : st) {
                if(cnt[j] == 1) {
                    ans[i].first.push_back(j);
                }
            }
            sort(ans[i].first.begin(), ans[i].first.end());
            ans[i].second = i + 1;
        }
        sort(ans.begin(), ans.end(), cmp);
        if(ans[0].first.size() == 0) {
            cout << ans[0].second << " " << ans[0].first.size();
        }else {
            cout << ans[0].second << " " << ans[0].first.size() << " ";
        }
        for(int i = 0; i < ans[0].first.size(); i++) {
            cout << ans[0].first[i];
            if(i != ans[0].first.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
        for(int i = 1; i <= 2; i++) {
            if(ans[0].first.size() == ans[i].first.size()) {
                if(ans[i].first.size() == 0) {
                    cout << ans[i].second << " " << ans[i].first.size();
                }else {
                    cout << ans[i].second << " " << ans[i].first.size() << " ";
                }
                for(int j = 0; j < ans[i].first.size(); j++) {
                    cout << ans[i].first[j];
                    if(j != ans[i].first.size() - 1) {
                        cout << " ";
                    }
                }
                cout << "\n";
            }
        }
    }
}

