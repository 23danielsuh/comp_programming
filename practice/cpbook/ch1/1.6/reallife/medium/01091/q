#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<string, int> vals;

string solve(int N) {
    vector<int> A(N); for(auto &x : A) cin >> x;
    if(N % 6 != 5 || (N + 1) / 6 < 5) 
        return "bad code";
    int mx = INT_MIN, mn = INT_MAX;
    for(auto &x : A)
        mx = max(mx, x), mn = min(mn, x);
    double avg = (mx + mn) / 2.0;
    string code;
    mx = INT_MIN, mn = INT_MAX;
    for(auto &x : A) {
        int temp = x;
        if(temp < avg) {
            temp *= 2;
        }
        mx = max(mx, temp), mn = min(mn, temp);
    }
    
    if(mn * 105 < mx * 95) 
        return "bad code";
    for(auto &x : A) 
        x > avg ? code.push_back('1') : code.push_back('0');
    if(code.substr(0, 5) != "00110") 
        reverse(code.begin(), code.end());
    if(code.substr(0, 5) != "00110")
        return "bad code";
    
    vector<int> encod;
    
    for(int i = 0; i < N; i += 6) {
        string temp = code.substr(i, 5);
        if(!vals.count(temp)) 
            return "bad code";
        if(i + 5 < N && code[i + 5] == 1) 
            return "bad code";
        else
            encod.push_back(vals[temp]);
    }
    
    int sz = (int) encod.size();
    
    if(encod[0] != -1 || encod[sz - 1] != -1) 
        return "bad code";
    
    for(int i = 1; i < sz - 1; i++) {
        if(encod[i] == -1) {
            return "bad code";
        }
    }
    
    int c = 0, k = 0, m = sz - 2;
    for(int i = 1; i <= m - 2; i++) {
        c += ((sz - 4 - i) % 10 + 1) * encod[i];
        c %= 11;
    }
    for(int i = 1; i <= m - 1; i++) {
        k += ((sz - 3 - i) % 9 + 1) * encod[i];
        k %= 11;
    }
    
    if(c != encod[m - 1]) return "bad C";
    if(k != encod[m]) return "bad K";
    
    string ans;
    for(int i = 1; i <= m - 2; i++) {
        encod[i] == 10 ? ans.push_back('-') : ans.push_back(encod[i] + '0');
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1;
    vals["00001"] = 0;
    vals["10001"] = 1;
    vals["01001"] = 2;
    vals["11000"] = 3;
    vals["00101"] = 4;
    vals["10100"] = 5;
    vals["01100"] = 6;
    vals["00011"] = 7;
    vals["10010"] = 8;
    vals["10000"] = 9;
    vals["00100"] = 10;
    vals["00110"] = -1;
    while(true) {
        int N; cin >> N;
        if(!N) break;
        cout << "Case " << tc << ": ";
        tc++;
        //solve(N);
        cout << solve(N) << "\n";
    }
}

