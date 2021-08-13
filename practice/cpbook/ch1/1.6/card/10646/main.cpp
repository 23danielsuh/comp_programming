#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc = 0; cin >> T;
    while(T--) {
        vector<string> bottom(27), top(25);
        for(auto &x : bottom) cin >> x;
        for(auto &x : top) cin >> x;
        int Y = 0, tp = 26;
        for(int i = 0; i < 3; i++) {
            char top_card = bottom[tp][0];
            int X = 10;
            if(top_card - '0' >= 2 && top_card - '0' <= 9) {
                X = top_card - '0';
            }
            Y += X;
            tp -= 10 - X + 1;
        }
        vector<string> new_stack;
        for(int i = 0; i <= tp; i++) {
            new_stack.emplace_back(bottom[i]);
        }

        for(auto &x : top) {
            new_stack.emplace_back(x);
        }
        tc++;
    }
}
