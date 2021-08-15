#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> location(1000000);

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        fill(location.begin(), location.end(), 1);
        int a, b, c; cin >> a >> b >> c;
        map<int, int> ladder;
        for(int i = 0; i < b; i++) {
            int x, y; cin >> x >> y;
            ladder[x] = y;
        }
        bool flag = 0;
        for(int i = 0; i < c; i++) {
            int roll; cin >> roll;
            if(flag) continue;
            int turn = i % a;
            if(ladder[location[turn] + roll] != 0) {
                location[turn] = ladder[location[turn] + roll];
            }else {
                location[turn] = location[turn] + roll;
            }
            if(location[turn] >= 100) {
                location[turn] = 100;
                flag = 1;
            }
        }
        for(int i = 0; i < a; i++) {
            cout << "Position of player " << i + 1 << " is " << location[i] << ".\n";
        }
    }
}

