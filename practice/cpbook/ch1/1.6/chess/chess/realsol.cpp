#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool start_vis[9][9], end_vis[9][9];

void visit(pair<int, int> start, int xdir, int ydir, bool x) {
    while(start.first > 0 && start.first < 9 && start.second > 0 && start.second < 9) {
        x ? (start_vis[start.first][start.second] = true) : (end_vis[start.first][start.second] = true);
        start.first += xdir;
        start.second += ydir;
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    map<char, int> mp;
    mp['A'] = 1;
    mp['B'] = 2;
    mp['C'] = 3;
    mp['D'] = 4;
    mp['E'] = 5;
    mp['F'] = 6;
    mp['G'] = 7;
    mp['H'] = 8;
    map<int, char> pm;
    pm[1] = 'A';
    pm[2] = 'B';
    pm[3] = 'C';
    pm[4] = 'D';
    pm[5] = 'E';
    pm[6] = 'F';
    pm[7] = 'G';
    pm[8] = 'H';
    while(T--) {
        memset(start_vis, 0, sizeof(start_vis));
        memset(end_vis, 0, sizeof(end_vis));
        pair<int, int> x, y;
        char a, c; int b, d;
        cin >> a >> b >> c >> d;
        if(a == c && b == d) {
            cout << 0 << " " << a << " " << b << "\n";
            continue;
        }
        x.first = mp[a]; x.second = b;
        y.first = mp[c]; y.second = d;
        visit(x, 1, 1, true);
        visit(x, -1, 1, true);
        visit(x, 1, -1, true);
        visit(x, -1, -1, true);
        visit(y, 1, 1, false);
        visit(y, -1, 1, false);
        visit(y, 1, -1, false);
        visit(y, -1, -1, false);
        pair<int, int> ans = {-1, -1};
        bool one = false;
        for(int i = 1; i <= 8; ++i) {
            for(int j = 1; j <= 8; ++j) {
                if(start_vis[i][j] && end_vis[i][j]) {
                    ans = {i, j};
                    if(ans == x || ans == y) {
                        one = true;
                    }
                }
            }
        }
        if(ans == make_pair(-1, -1)) {
            cout << "Impossible" << "\n";
            continue;
        }
        if(one) {
            cout << 1 << " " << a << " " << b << " " << c << " " << d << "\n";
            continue;
        }
        vector<pair<int, int>> sol;
        if(ans != x) {
            sol.push_back(x);
        }
        sol.push_back(ans);
        if(ans != y) {
            sol.push_back(y);
        }
        cout << (int) sol.size() - 1 << " ";
        for(auto &i : sol) cout << pm[i.first] << " " << i.second << " ";
        cout << "\n";
    }
}

