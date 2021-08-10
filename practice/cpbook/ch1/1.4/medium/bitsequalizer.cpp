#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        string a, b; cin >> a >> b;
        int N = (int) a.size();
        map<char, int> ca, cb, cmod;
        vector<pair<int, int>> indices;
        for(int i = 0; i < N; i++) {
            ca[a[i]]++;
            cb[b[i]]++;
            if(a[i] == '?') indices.push_back({i, b[i]});
        }
        sort(indices.begin(), indices.end(), [](const pair<int, int> &temp_a, const pair <int, int> &temp_b) {
                return temp_a.second > temp_b.second;
                });
        int need = cb['1'] - ca['1']; string mod = a;
        if(need < 0) { cout << -1 << "\n"; continue; }
        //assert(indices.size() >= need);
        for(int i = 0; i < min(need, (int) indices.size()); i++) {
            mod[indices[i].first] = '1';
        }
        for(int i = min(need, (int) indices.size()); i < (int) indices.size(); i++) {
            mod[indices[i].first] = '0';
        }
        for(char c : mod) {
            mod[c]++;
        }

        cout << mod << "\n";
    }
}
