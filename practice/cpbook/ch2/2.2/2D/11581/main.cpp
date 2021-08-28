#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 3;
int grid[mxN][mxN], store_grid[mxN][mxN];

bool check() {
    set<int> st;
    bool flag = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        for(int i = 0; i < 3; i++) {
            string S; cin >> S;
            for(int j = 0; j < 3; j++) {
                grid[i][j] = S[j] - '0';
                store_grid[i][j] = S[j] - '0';
            }
        }
        int cnt = 0;
        while(!check()) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    int temp = 0;
                    if(i - 1 >= 0) {
                        temp += store_grid[i - 1][j];
                    }
                    if(j - 1 >= 0) {
                        temp += store_grid[i][j - 1];
                    }
                    if(i + 1 < 3) {
                        temp += store_grid[i + 1][j];
                    }
                    if(j + 1 < 3) {
                        temp += store_grid[i][j + 1];
                    }
                    temp %= 2;
                    grid[i][j] = temp;
                }
            }
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    store_grid[i][j] = grid[i][j];
                }
            }
            cnt++;
        }
        cout << cnt - 1 << "\n";
    }
}

