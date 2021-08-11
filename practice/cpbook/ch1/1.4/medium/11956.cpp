#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 105;
int ans[mxN];

string hexa(int x) {
    stringstream sstream;
    sstream << hex << x;
    string result = sstream.str();
    return result;
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc = 1; cin >> T;
    while(T--) {
        memset(ans, 0, sizeof(ans));
        string S; cin >> S;
        int cur = 0;
        for(char c : S) {
            if(c == '>') {
                cur++;
                if(cur >= 100) {
                    cur = 0;
                }
            }else if(c == '<') {
                cur--;
                if(cur < 0) {
                    cur = 99;
                }
            }else if(c == '+') {
                ans[cur]++;
                if(ans[cur] > 255) {
                    ans[cur] = 0;
                }
            }else if(c == '-') {
                ans[cur]--;
                if(ans[cur] < 0) {
                    ans[cur] = 255;
                }
            }
        }
        cout << "Case " << tc << ": ";
        for(int i = 0; i < 100; i++) {
            if(i < 99) {
                printf("%02X ", ans[i]);
            }else {
                printf("%02X\n", ans[i]);
            }
        }
        tc++;
    }
}

