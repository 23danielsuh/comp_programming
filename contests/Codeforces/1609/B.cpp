#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
string S;

bool check(int pos, char c) {
    //look at range [pos - 2, pos + 2]
    for(int it = 0; it < 3; it++) {
        string cur = "";
        bool ok = 1;
        for(int i = pos - 2; i <= pos; i++) {
            if(i < 0 || i >= N) { ok = 0; break; }
            cur += S[i];
        }
        pos++;
        if(!ok) continue;
        if(cur == "abc") {
            cur[2 - it] = c;
            if(cur != "abc") {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int cur = 0;
    cin >> N >> Q;
    cin >> S;
    for(int i = 0; i < N - 2; i++) {
        if(S[i] == 'a' && S[i + 1] == 'b' && S[i + 2] == 'c') {
            cur++;
        }
    }
    while(Q--) {
        int x; char c; cin >> x >> c; x--;
        if(S[x] == c) { cout << cur << "\n"; continue; }
        if(c == 'a') {
            if(S[x] != 'a' && x + 1 < N && x + 2 < N && S[x + 1] == 'b' && S[x + 2] == 'c') {
                cur++;
            }
            //do you decrease?
            if(check(x, 'a')) {
                cur--;
            }
        }else if(c == 'b') {
            if(S[x] != 'b' && x - 1 >= 0 && x + 1 < N && S[x - 1] == 'a' && S[x + 1] == 'c') {
                cur++;
            }
            if(check(x, 'b')) {
                cur--;
            }
        }else {
            if(S[x] != 'c' && x - 1 >= 0 && x - 2 >= 0 && S[x - 1] == 'b' && S[x - 2] == 'a') {
                cur++;
            }
            if(check(x, 'c')) {
                cur--;
            }
        }
        cout << cur << "\n";
        S[x] = c;
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

//changing the character at index i affects the elements at i - 1 and i + 1
//keep a vector of what the current status of each element is.
//if index i changes to an a, then i + 1's 2-bit gets turned on, i + 2's 3-bit gets turned on
//if index i changes to an b, then i - 1's 1-bit gets turned on, i + 1's 3-bit gets turned on
//if index i changes to an c, then i - 2's 1-bit gets turned on, i - 1's 2-bit gets turned on

//if index i changes to an a, check if  

