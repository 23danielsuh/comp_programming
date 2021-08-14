#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string check(pair<int, int> cur) {
    if(cur.first % 2 != cur.second % 2) {
        return "white";
    }
    return "black";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    map<char, int> mp;
    mp['A'] = 1;
    mp['B'] = 2;
    mp['C'] = 3;
    mp['D'] = 4;
    mp['E'] = 5;
    mp['F'] = 6;
    mp['G'] = 7;
    mp['H'] = 8;
    while(T--) {
        pair<char, char> x_in, y_in;
        cin >> x_in.first >> x_in.second >> y_in.first >> y_in.second;
        pair<int, int> x, y;
        x.first = mp[x_in.first]; x.second = x_in.second - '0';
        y.first = mp[y_in.first]; y.second = y_in.second - '0';
        if(check(x) != check(y)) {
            cout << "Impossible\n";
        }

        pair<int, int> go;
        if(check(x) == "white") {
            go = {4, 5};
        }else {
            go = {4, 4};
        }

        vector<int> ans;
        pair<int, int> temp = x; bool pos = 0;
        while(temp.first > 0 && temp.second > 0) {
            if(abs(temp.first - go.first) == abs(temp.second - go.second)){
                ans.emplace_back(temp.first); ans.emplace_back(temp.second);
                pos = 1;
            } 
            temp.first--; temp.second--;
        }
        while(temp.first < 9 && temp.second > 0) {
            if(abs(temp.first - go.first) == abs(temp.second - go.second)) {
                ans.emplace_back(temp.first); ans.emplace_back(temp.second);
                pos = 1;
            }
            temp.first++; temp.second--;
        }
        while(temp.first > 0 && temp.second < 9) {
            if(abs(temp.first - go.first) == abs(temp.second - go.second)) {
                ans.emplace_back(temp.first); ans.emplace_back(temp.second);
                pos = 1;
            }
            temp.first--; temp.second++;
        }
        while(temp.first < 9 && temp.second < 9) {
            if(abs(temp.first - go.first) == abs(temp.second - go.second)) {
                ans.emplace_back(temp.first); ans.emplace_back(temp.second);
                pos = 1;
            }
            temp.first++; temp.second++;
        }

        ans.emplace_back(go.first); ans.emplace_back(go.second);

        while(go.first > 0 && temp.second > 0) {
            if(abs(temp.first - go.first) == abs(temp.second - go.second)) {
                ans.emplace_back(temp.first); ans.emplace_back(temp.second);
                pos = 1;
            }
            temp.first--; temp.second--;
        }
        while(temp.first > 0 && temp.second > 0) {
            if(abs(temp.first - go.first) == abs(temp.second - go.second)){
                ans.emplace_back(temp.first); ans.emplace_back(temp.second);
                pos = 1;
            } 
            temp.first--; temp.second--;
        }

    }
}

