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
    int it = N / 2 + N % 2;
    for(int i = 0; i < it; i++) {
        for(int j = 0; j < it; j++) {
            int need = 4;
            pair<int, int> tl = make_pair(i, j);
            pair<int, int> tr = make_pair(i, N - j - 1);
            pair<int, int> bl = make_pair(N - i - 1, j);
            pair<int, int> br = make_pair(N - i - 1, N - j - 1);
            //cout << "PROCESSED " << i << " " << j << "\n";
            //cout << tl.first << " " << tl.second << "\n";
            //cout << tr.first << " " << tr.second << "\n";
            //cout << bl.first << " " << bl.second << "\n";
            //cout << br.first << " " << br.second << "\n";
            //cout << "\n";
            if(tl == tr && bl == br && bl == tr) {
                need = 1;
            }else if((tl == tr && bl == br)|| (tl == bl && tr == br)) {
                need = 2;
            }
            if(need == 1) {
                if(mods[1].empty()) {
                    if(mods[3].empty()) {
                        cout << "NO\n";
                        return;
                    }else {
                        grid[tl.first][tl.second] = *mods[3].rbegin();
                        mods[2].push_back(*mods[3].rbegin());
                        mods[3].pop_back();
                    }
                }else {
                    grid[tl.first][tl.second] = *mods[1].rbegin();
                    mods[1].pop_back();
                }
            }else if(need == 2) {
                if(mods[2].empty()) {
                    if(mods[4].empty() && mods[3].empty()) {
                        cout << "NO\n";
                        return;
                    }else if(mods[4].empty()) {
                        grid[tl.first][tl.second] = *mods[3].rbegin();
                        grid[tr.first][tr.second] = *mods[3].rbegin();
                        grid[bl.first][bl.second] = *mods[3].rbegin();
                        grid[br.first][br.second] = *mods[3].rbegin();
                        mods[1].push_back(*mods[3].rbegin());
                        mods[3].pop_back();
                    }else {
                        grid[tl.first][tl.second] = *mods[4].rbegin();
                        grid[tr.first][tr.second] = *mods[4].rbegin();
                        grid[bl.first][bl.second] = *mods[4].rbegin();
                        grid[br.first][br.second] = *mods[4].rbegin();
                        mods[2].push_back(*mods[4].rbegin());
                        mods[4].pop_back();
                    }
                }else {
                    grid[tl.first][tl.second] = *mods[2].rbegin();
                    grid[tr.first][tr.second] = *mods[2].rbegin();
                    grid[bl.first][bl.second] = *mods[2].rbegin();
                    grid[br.first][br.second] = *mods[2].rbegin();
                    mods[2].pop_back();
                }
            }else {
                if(mods[4].empty()) {
                    bool flag = 0;
                    int index1 = -1, index2 = -1, val = -1;
                    for(int i1 = 0; i1 < (int) mods[2].size(); i1++) {
                        for(int i2 = 0; i2 < (int) mods[2].size(); i2++) {
                            if(i1 != i2) {
                                if(mods[2][i1] == mods[2][i2]) {
                                    flag = 1;
                                    index1 = i1, index2 = i2, val = mods[2][i1];
                                }
                            }
                        }
                    }
                    if(!flag) {
                        cout << "NO\n";
                        return;
                    }else {
                        mods[2].erase(mods[2].begin() + index1);
                        mods[2].erase(mods[2].begin() + index2 - 1);
                        grid[tl.first][tl.second] = val;
                        grid[tr.first][tr.second] = val;
                        grid[bl.first][bl.second] = val;
                        grid[br.first][br.second] = val;
                    }
                }else {
                    grid[tl.first][tl.second] = *mods[4].rbegin();
                    grid[tr.first][tr.second] = *mods[4].rbegin();
                    grid[bl.first][bl.second] = *mods[4].rbegin();
                    grid[br.first][br.second] = *mods[4].rbegin();
                    mods[4].pop_back();
                }
            }
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
