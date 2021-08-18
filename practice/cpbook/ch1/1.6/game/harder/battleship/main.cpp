#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2005;
char grid1[mxN][mxN], grid2[mxN][mxN];
int w, h, N;

void output() {
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            cout << grid1[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            cout << grid2[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        memset(grid1, 0, sizeof grid1);
        memset(grid2, 0, sizeof grid2);
        cin >> w >> h >> N;
        int ships1 = 0, ships2 = 0;
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {
                cin >> grid1[i][j];
                if(grid1[i][j] == '#') {
                    ships1++;
                }
            }
        }
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {
                cin >> grid2[i][j];
                if(grid2[i][j] == '#') {
                    ships2++;
                }
            }
        }
        vector<pair<int, int>> shots(N); for(auto &x : shots) cin >> x.first >> x.second;
        bool flag1 = 0, flag2 = 0;
        string ans; int turn = 0;
        
        cout << ans << "\n";
    }
}

