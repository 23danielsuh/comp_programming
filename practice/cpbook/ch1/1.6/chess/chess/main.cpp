#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string check(pair<int, int> cur) {
    if(cur.first % 2 != cur.second % 2) {
        return "white";
    }
    return "black";
}

vector<int> ans;
void can(pair<int, int> go, pair<int, int> original) {
    pair<int, int> temp;
    temp = original;
    bool pos = 0;
    while(temp.first > 0 && temp.second > 0) {
        if(abs(temp.first - go.first) == abs(temp.second - go.second)){
            ans.emplace_back(temp.first); ans.emplace_back(temp.second);
            pos = 1;
            break;
        } 
        temp.first--; temp.second--;
    }
    if(pos) return;
    temp = original;
    while(temp.first < 9 && temp.second > 0) {
        if(abs(temp.first - go.first) == abs(temp.second - go.second)) {
            ans.emplace_back(temp.first); ans.emplace_back(temp.second);
            pos = 1;
            break;
        }
        temp.first++; temp.second--;
    }
    if(pos) return;
    temp = original;
    while(temp.first > 0 && temp.second < 9) {
        if(abs(temp.first - go.first) == abs(temp.second - go.second)) {
            ans.emplace_back(temp.first); ans.emplace_back(temp.second);
            pos = 1;
            break;
        }
        temp.first--; temp.second++;
    }
    if(pos) return;
    temp = original;
    while(temp.first < 9 && temp.second < 9) {
        if(abs(temp.first - go.first) == abs(temp.second - go.second)) {
            ans.emplace_back(temp.first); ans.emplace_back(temp.second);
            pos = 1;
            break;
        }
        temp.first++; temp.second++;
    }
    if(pos) return;
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
    map<int, char> pm;
    pm[1] = 'A';
    pm[2] = 'B';
    pm[3] = 'C';
    pm[4] = 'D';
    pm[5] = 'E';
    pm[6] = 'F';
    pm[7] = 'G';
    pm[8] = 'H';
    while(T--) {
        ans.clear();
        pair<char, char> x_in, y_in;
        cin >> x_in.first >> x_in.second >> y_in.first >> y_in.second;
        pair<int, int> x, y;
        x.first = mp[x_in.first]; x.second = x_in.second - '0';
        y.first = mp[y_in.first]; y.second = y_in.second - '0';
        if(check(x) != check(y)) {
            cout << "Impossible\n";
            continue;
        }

        ans.emplace_back(x.first); ans.emplace_back(x.second);
        pair<int, int> go;
        if(check(x) == "white") {
            go = {4, 5};
        }else {
            go = {4, 4};
        }
        can(go, x);
        ans.emplace_back(go.first); ans.emplace_back(go.second);
        can(y, go);
        vector<pair<int, int>> ans_f;
        for(int i = 0; i < (int) ans.size(); i += 2) {
            ans_f.push_back(make_pair(ans[i], ans[i + 1]));
        }
        cout << (int) ans_f.size() << " ";
        for(int i = 0; i < (int) ans_f.size(); i++) {
            if(i == 0) {
                cout << pm[ans_f[i].first] << " " << ans_f[i].second << " ";
            }else {
                if(ans_f[i - 1].first == ans_f[i].first && ans_f[i - 1].second == ans_f[i].second) {
                    continue;
                }
                cout << pm[ans_f[i].first] << " " << ans_f[i].second << " ";
            }
        }
        cout << pm[y.first] << " " << y.second;
        cout << "\n";
    }
}

