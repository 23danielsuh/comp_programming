#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        int A, B; cin >> A >> B;
        if(!A && !B) break;
        set<int> betty, alice;
        for(int i = 0; i < A; i++) {
            int x; cin >> x;
            alice.insert(x);
        }
        for(int i = 0; i < B; i++) {
            int x; cin >> x;
            betty.insert(x);
        }
        betty.insert(INT_MAX);
        for(auto x = alice.begin(); x != alice.end(); ) {
            auto it = betty.lower_bound(*x);
            if(*it == INT_MAX) {
                x++;
                continue;
            }
            if(*it == *x) {
                betty.erase(it);
                x = alice.erase(x);
            }else {
                x++;
            }
        }
        cout << min((int) betty.size() - 1, (int) alice.size()) << "\n";
    }
}

