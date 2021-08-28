#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //SKIP PROBLEM BC TOO EASY 
    map<string, vector<string>> mp;

    while(true) {
        string S; getline(cin, S);
        if(S == "END") break;
        string cur = "";
        vector<string> A;
        for(int i = 0; i < (int) S.size(); i++) {
            if(S[i] == ' ') {
                A.push_back(cur);
                cur = "";
            }else {
                cur += S[i];
            }
        }
        if(cur.size()) A.push_back(cur);
        set<string> ans;
    }
}

