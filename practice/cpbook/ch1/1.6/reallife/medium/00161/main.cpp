#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

void solve(vector<int> times) {
    vector<bool> cur_status((int) times.size());
    int ans = -1;
    bool g_flag = 0;
    for(int i = 0; i <= 18000; i++) {
        bool flag = 1;
        for(auto &j : times) {
            int len_cycle = 2 * j, num_cycles = fdiv(i, len_cycle), x = i % (2 * j);
            if(!g_flag || x >= j - 5) {
                flag = 0;
            }
            if(x >= j - 5) {
                g_flag = 1;
            }
        }
        if(flag) {
            ans = i;
            break;
        }
    }
    if(ans == -1) {
        cout << "Signals fail to synchronise in 5 hours\n";
        return;
    }
    int hour = fdiv(ans, 3600);
    ans -= hour * 3600;
    int minute = fdiv(ans, 60);
    ans -= minute * 60;
    if(to_string(hour).size() == 1) {
        cout << 0 << hour;
    }else {
        cout << hour;
    }
    cout << ":";
    if(to_string(minute).size() == 1) {
        cout << 0 << minute;
    }else {
        cout << minute;
    }
    cout << ":";
    if(to_string(ans).size() == 1) {
        cout << 0 << ans;
    }else {
        cout << ans;
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> A;
    int cnt = 0;
    while(true) {
        int x; cin >> x;
        if(!x) {
            if(!cnt) {
                solve(A);
                A.clear();
            }
            cnt++;
            if(cnt > 3) {
                break;
            }
        }else {
            cnt = 0;
            A.push_back(x);
        }
    }
}

