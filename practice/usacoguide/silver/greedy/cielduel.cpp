#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    if(a.first != b.first) {
        return a.first == "ATK";
    }else {
        if(a.first == "ATK") {
            return a.second < b.second;
        }
    }
    return a.second > b.second;
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<pair<string, int>> jiro(N); 
    multiset<int> ciel;
    for(auto &x : jiro) cin >> x.first >> x.second;
    for(int i = 0; i < M; i++) {
        int x; cin >> x;
        ciel.insert(x);
    }
    ciel.insert(INT_MAX);
    sort(jiro.begin(), jiro.end(), cmp);
    //for(auto &x : jiro) cout << x.first << " " << x.second << "\n";
    for(auto &x : ciel) cout << x << " ";
    int cur_i = 0, ans = 0;
    bool flag = 0;
    for(int i = 0; i < M;) {
        //where do you allocate x points?
        assert(!ciel.empty());
        
        if(!flag && cur_i >= N) {
            ans += *(----ciel.end());
            ciel.erase(ciel.find(*(----ciel.end())));
            i++;
            continue;
        }
        if(cur_i >= N && flag) {
            break;
        }
        
        if(cur_i < N && jiro[cur_i].first == "ATK") {
            cout << *(----ciel.end()) << " ";
            cout << jiro[cur_i].second << "\n";
            if(*(----ciel.end()) >= jiro[cur_i].second) {
                ans += *(----ciel.end()) - jiro[cur_i].second;
                cur_i++;
                i++;
                ciel.erase(ciel.find(*(----ciel.end())));
                continue;
            }else {
                flag = 1;
                cur_i++;
                continue;
            }
        }
        if(cur_i < N && jiro[cur_i].first == "DEF") {
            //find the element that is closest to jiro[cur_i].second using upper_bound, and continue
            auto it = ciel.upper_bound(jiro[cur_i].second);
            if(*it == INT_MAX) {
                break;
            }else {
                ciel.erase(ciel.find(*ciel.upper_bound(jiro[cur_i].second)));
                i++;
                cur_i++;
                continue;
            }
        }
    }
    cout << ans << "\n";
}

