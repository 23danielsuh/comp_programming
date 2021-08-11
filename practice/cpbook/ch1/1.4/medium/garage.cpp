#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 2005;
int carSpot[mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<int> prices(N + 1), cars(M + 1);
    for(int i = 1; i <= N; i++) cin >> prices[i];
    for(int i = 1; i <= M; i++) cin >> cars[i];
    set<int> free;
    for(int i = 1; i <= N; i++) {
        free.insert(i);
    }
    deque<int> line;
    int ans = 0;
    for(int i = 0; i < 2 * M; i++) {
        int step; cin >> step;
        if(step > 0) {
            if(free.empty()) {
                line.push_back(step);
            }else {
                int space = *free.begin();
                free.erase(*free.begin());
                ans += cars[step] * prices[space];
                carSpot[step] = space;
            }
        }else {
            free.insert(carSpot[-step]);
        }
        if(!free.empty() && !line.empty()) {
            int car = *line.begin();
            ans += cars[car] * prices[carSpot[-step]];
            carSpot[car] = carSpot[-step];
            free.erase(free.lower_bound(carSpot[-step]));
            line.pop_front();
        }
    }
    cout << ans << "\n";
}

