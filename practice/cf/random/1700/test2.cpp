#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 25;
int grid[mxN][mxN], cnt[1005];
vector<int> mods[5];

void solve() {
    int N; cin >> N;
    vector<int> A(N * N);
    for(int i = 0; i < N * N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    for(int i = 0; i < 1005; i++) {
        if(cnt[i] != 0) {
            while(cnt[i] > 0) {
                if(cnt[i] - 4 <= 0) {
                    mods[cnt[i]].push_back(i);
                    break;
                }
                mods[4].push_back(i);
                cnt[i] -= 4;
            }
        }
    }
    if(N % 2 == 0) {
        if(mods[1].size() || mods[2].size() || mods[3].size()) {
            cout << "NO\n";
            return;
        }
    }else {
        if(mods[2].size() != N - 1) {
            
        }
    }
    int it = N / 2 + N % 2;
    for(int i = 0; i < it; i++) {
        for(int j = 0; j < it; j++) {
            int need = 4;
            pair<int, int> tl = make_pair(i, j);
            pair<int, int> tr = make_pair(i, N - j - 1);
            pair<int, int> bl = make_pair(N - i - 1, j);
            pair<int, int> br = make_pair(N - i - 1, N - j - 1);
            if(tl == tr && bl == br && bl == tr) {
                need = 1;
            }else if((tl == tr && bl == br)|| (tl == bl && tr == br)) {
                need = 2;
            }
            grid[tl.first][tl.second] = *mods[need].rbegin();
            grid[bl.first][bl.second] = *mods[need].rbegin();
            grid[tr.first][tr.second] = *mods[need].rbegin();
            grid[br.first][br.second] = *mods[need].rbegin();
            mods[need].pop_back();
        }
    }
    cout << "YES\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
