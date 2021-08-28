#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check(int a, int b, int c, int d, int e, int N) {
    return a >= 0 && a < N && b >= 0 && b < N && c >= 0 && c < N && d >= 0 && d < N && e >= 0 && e < N;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1;
    map<array<int, 5>, int> weights;
    map<int, char> character;
    map<array<int, 5>, int> pos;
    pos[{0, 0, 0, 0, 1}] = 1;
    pos[{1, 0, 0, 0, 1}] = 1;
    pos[{0, 1, 0, 0, 1}] = 1;
    pos[{1, 1, 0, 0, 0}] = 1;
    pos[{0, 0, 1, 0, 1}] = 1;
    pos[{1, 0, 1, 0, 0}] = 1;
    pos[{0, 1, 1, 0, 0}] = 1;
    pos[{0, 0, 0, 1, 1}] = 1;
    pos[{1, 0, 0, 1, 0}] = 1;
    pos[{1, 0, 0, 0, 0}] = 1;
    pos[{0, 0, 1, 0, 0}] = 1;
    pos[{0, 0, 1, 1, 0}] = 100;
    character[0] = '0';
    character[1] = '1';
    character[2] = '2';
    character[3] = '3';
    character[4] = '4';
    character[5] = '5';
    character[6] = '6';
    character[6] = '6';
    character[7] = '7';
    character[8] = '8';
    character[9] = '9';
    character[10] = '-';
    weights[{0, 0, 0, 0, 1}] = 0;
    weights[{1, 0, 0, 0, 1}] = 1;
    weights[{0, 1, 0, 0, 1}] = 2;
    weights[{1, 1, 0, 0, 0}] = 3;
    weights[{0, 0, 1, 0, 1}] = 4;
    weights[{1, 0, 1, 0, 0}] = 5;
    weights[{0, 1, 1, 0, 0}] = 6;
    weights[{0, 0, 0, 1, 1}] = 7;
    weights[{1, 0, 0, 1, 0}] = 8;
    weights[{1, 0, 0, 0, 0}] = 9;
    weights[{0, 0, 1, 0, 0}] = 10;
    while(true) {
        int N; cin >> N;
        if(!N) break;
        cout << "Case " << tc << ": ";
        tc++;
        vector<int> A(N); for(auto &x : A) cin >> x;
        if(N % 6 != 5 || (N + 1) / 6 < 5) {
            cout << "bad code";
            continue;
        }
        pair<int, int> vals = make_pair(INT_MAX, INT_MAX);
        for(int val1 = 0; val1 < N; val1++) {
            bool ok = 1;
            for(int val2 = 0; val2 < N; val2++) {
                ok = 1;
                if(val1 == val2) continue;
                pair<double, double> range1, range2;
                range1 = make_pair((double) A[val1] * 0.95, (double) A[val1] * 1.05);
                range2 = make_pair((double) A[val2] * 0.95, (double) A[val2] * 1.05);
                for(auto &x : A) {
                    if(!((double) x >= range1.first && (double) x <= range1.second) && !((double) x >= range2.first && (double) x <= range2.second)) {
                        ok = 0;
                    }
                }
                if(ok) {
                    vals = make_pair(A[val1], A[val2]);
                    break;
                }
            }
            if(ok) break;
        }
        bool bad = 0;
        if(vals == make_pair(INT_MAX, INT_MAX)) {
            bad = 1;
        }
        //if(vals.first * 1.05 < vals.second * 0.95) {
            //bad = 1;
        //}
        if(bad) {
            cout << "bad code\n";
            continue;
        }
        vector<array<int, 5>> fcodes(100), bcodes(100);
        if(vals.first >= vals.second) {
            swap(vals.first, vals.second);
        }
        int cnt = 0;
        for(int i = 0; i < N; i += 6) {
            if(!check(i, i + 1, i + 2, i + 3, i + 4, N)) {
                bad = 1;
                break;
            }
            fcodes[cnt] = {A[i], A[i + 1], A[i + 2], A[i + 3], A[i + 4]};
            if(i + 5 < N) {
                if(!(A[i + 5] >= vals.first * 0.95 && A[i + 5] <= vals.first * 1.05)) {
                    bad = 1;
                    break;
                }
            }
            cnt++;
        }
        if(bad) {
            cout << "bad code\n";
            continue;
        }
        cnt = 0;
        for(int i = N - 1; i >= 0; i -= 6) {
            if(!check(i, i - 1, i - 2, i - 3, i - 4, N)) {
                bad = 1;
                break;
            }
            bcodes[cnt] = {A[i], A[i - 1], A[i - 2], A[i - 3], A[i - 4]};
            if(i - 5 >= 0) {
                if(!(A[i - 5] >= vals.first * 0.95 && A[i - 5] <= vals.first * 1.05)) {
                    bad = 1;
                    break;
                }
            }
            cnt++;
        }
        if(bad) {
            cout << "bad code\n";
            continue;
        }
        for(int i = 0; i < cnt; i++) {
            for(auto &x : fcodes[i]) {
                if(x >= vals.first * 0.95 && x <= vals.first * 1.05) {
                    x = 0;
                }
                if(x >= vals.second * 0.95 && x <= vals.second * 1.05) {
                    x = 1;
                }
            }
        }
        for(int i = 0; i < cnt; i++) {
            for(auto &x : bcodes[i]) {
                if(x >= vals.first * 0.95 && x <= vals.first * 1.05) {
                    x = 0;
                }
                if(x >= vals.second * 0.95 && x <= vals.second * 1.05) {
                    x = 1;
                }
            }
        }
        bool forward = 0;
        array<int, 5> check = {0, 0, 1, 1, 0};
        if(fcodes[0] == check && fcodes[cnt - 1] == check) {
            forward = 1;
        }else if(bcodes[0] == check && bcodes[cnt - 1] == check) {
            forward = 0;
        }else {
            bad = 1;
        }
        if(bad) {
            cout << "bad code\n";
            continue;
        }
        vector<array<int, 5>> codes;
        if(forward) {
            codes = fcodes;
        }else {
            codes = bcodes;
        }
        for(int i = 0; i < cnt; i++) {
            if(!pos[codes[i]]) {
                bad = 1;
            }
        }
        for(int i = 1; i < cnt - 1; i++) {
            if(pos[codes[i]] == 100) {
                bad = 1;
            }
        }
        if(bad) {
            cout << "bad code\n";
            continue;
        }
        //C check character: codes[N - 3]
        //K check character: codes[N - 2]
        int c = 0, k = 0;
        for(int i = 1; i <= cnt - 3; i++) {
            c += ((cnt - 4 - i) % 10 + 1) * weights[codes[i]];
        }
        for(int i = 1; i <= cnt - 2; i++) {
            k += ((cnt - 4 - i + 1) % 9 + 1) * weights[codes[i]];
        }
        
        c %= 11;
        k %= 11;
        
        vector<char> ans;
        for(int i = 1; i < cnt - 1; i++) {
            ans.push_back(character[weights[codes[i]]]);
        }
        if(bad) {
            cout << "bad code\n";
            continue;
        }
        if(character[weights[codes[cnt - 3]]] != character[c]) {
            cout << "bad C\n";
            continue;
        }
        if(character[weights[codes[cnt - 2]]] != character[k]) {
            cout << "bad K\n";
            continue;
        }
        for(int i = 1; i < cnt - 3; i++) {
            cout << character[weights[codes[i]]];
        }
        cout << "\n";
    }
}

