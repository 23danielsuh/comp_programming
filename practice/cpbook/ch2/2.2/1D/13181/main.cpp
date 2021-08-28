#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    string S; 
    while(cin >> S) {
        set<int> indices;
        int N = (int) S.size();
        for(int i = 0; i < N; i++) {
            if(S[i] == 'X') {
                indices.insert(i);
            }
        }
        int mx = 0;
        indices.insert(0);
        indices.insert(N);
        for(int i = 0; i < N; i++) {
            if(S[i] == 'X') continue;
            auto it = indices.upper_bound(i);
            //cout << "MX: " << mx << "\n";
            if(i == 0) {
                mx = max(mx, abs(i - *it) - 1);
                continue;
            }
            auto it2 = --indices.upper_bound(i);
            if(i == N - 1) {
                mx = max(mx, abs(i - *it2) - 1);
                continue;
            }
            //cout << i << " " << *it << " " << *it2 << "\n";
            mx = max(mx, min(abs(i - *it) - 1, abs(i - *it2) - 1));
            //cout << mx << " ";
        }
        cout << mx << "\n";
    }
}

