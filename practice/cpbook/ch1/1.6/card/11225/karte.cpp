#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string S; cin >> S;
    map<string, bool> visited;
    map<char, vector<int>> all;
    assert((int) S.size() % 3 == 0);
    for(int i = 0; i < (int) S.size(); i += 3) {
        string cur = "";
        cur += S[i];
        cur += S[i + 1];
        cur += S[i + 2];
        if(visited[cur]) {
            cout << "GRESKA" << "\n";
            return 0;
        }
        visited[cur] = true;

        char suit = S[i];
        string num_str = "";
        num_str += S[i + 1];
        num_str += S[i + 2];
        int num = stoi(num_str);
        all[suit].push_back(num);
    }
    cout << 13 - (int) all['P'].size() << " ";
    cout << 13 - (int) all['K'].size() << " ";
    cout << 13 - (int) all['H'].size() << " ";
    cout << 13 - (int) all['T'].size() << " ";
}

