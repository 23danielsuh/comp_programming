#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool pedler(string s) {
    return (s == "oneoftrumps" || s == "twenty-oneoftrumps" || s == "fool");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc = 1; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<array<string, 3>> A(N);
        for(int i = 0; i < N; i++) {
            string a, b, c;
            cin >> a;
            if(a == "fool") {
                A[i] = {a, "", ""};
                continue;
            }
            cin >> b >> c;
            A[i] = {a, b, c};
        }
        double sum_points = 0;
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            string a = A[i][0], b = A[i][1], c = A[i][2];
            if(pedler(a + b + c)) {
                cnt++;
                sum_points += 4.5;
                continue;
            }
            if(a == "king") {
                sum_points += 4.5;
                continue;
            }
            if(a == "queen") {
                sum_points += 3.5;
                continue;
            }
            if(a == "knight") {
                sum_points += 2.5;
                continue;
            }
            if(a == "jack") {
                sum_points += 1.5;
                continue;
            }
            sum_points += 0.5;
        }
        double need_points = 56;
        if(cnt == 1) {
            need_points = 51;
        }else if(cnt == 2) {
            need_points = 41;
        }else if(cnt == 3){
            need_points = 36;
        }else if(cnt == 0) {
            need_points = 56;
        }else {
            assert(false);
        }
        cout << "Hand #" << tc << "\n";
        tc++;
        if(sum_points >= need_points) {
            cout << "Game won by " << sum_points - need_points << " point(s).";
        }else {
            cout << "Game lost by " << need_points - sum_points << " point(s).";
        }
        cout << "\n";
        if(T >= 1) {
            cout << "\n";
        }
    }
}

