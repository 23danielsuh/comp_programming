#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 101;
vector<pair<int, int>> players(mxN);

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        int N, K; cin >> N;
        if(N == 0) {
            break;
        }
        cin >> K;
        fill(players.begin(), players.end(), make_pair(0, 0));
        for(int i = 0; i < (K * N * (N - 1)) / 2; i++) {
            int p1, p2; string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;
            if(m1 == "rock") {
                if(m2 == "scissors") {
                    players[p1].first++;
                    players[p2].second++;
                }else if(m2 == "paper") {
                    players[p2].first++;
                    players[p1].second++;
                }
            }else if(m1 == "scissors") {
                if(m2 == "rock") {
                    players[p2].first++;
                    players[p1].second++;
                }else if(m2 == "paper") {
                    players[p1].first++;
                    players[p2].second++;
                }
            }else {
                if(m2 == "scissors") {
                    players[p2].first++;
                    players[p1].second++;
                }else if(m2 == "rock") {
                    players[p1].first++;
                    players[p2].second++;
                }
            }
        }
        cout << fixed << setprecision(3);
        for(int i = 1; i <= N; i++) {
            if(players[i].first + players[i].second == 0) {
                cout << "-" << "\n";
                continue;
            }
            cout << double(players[i].first) / double(players[i].first + players[i].second) << "\n";
        }
        cout << "\n";
    }
}
