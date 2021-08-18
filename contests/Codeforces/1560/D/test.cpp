#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string S = "1112";
    int N = (int) S.size();
    string target = "2345";
    int start = 0, cnt = 0;
    for(int i = 0; i < (int) target.size(); i++) {
        bool flag = 0;
        for(int j = start; j < N; j++) {
            if(S[j] == target[i]) {
                start = j + 1;
                flag = 1;
                break;
            }
        }
        if(!flag) break;
        cnt++;
    }
    int steps = N - cnt;
    steps += (int) target.size() - cnt;
    cout << steps << "\n";
}

