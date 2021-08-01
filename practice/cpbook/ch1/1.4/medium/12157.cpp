#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, i = 0; cin >> T;
    while(T--) {
        i++;
        cout << "Case " << i << ": ";
        int N; cin >> N;
        vector<int> A(N); for(auto &x : A) cin >> x;
        int mile = 0, juice = 0;
        for(auto &x : A) {
            int mile_cnt = 0, juice_cnt = 0;
            if(x % 30 == 0) {
                mile_cnt = x / 30 + 1;
            }else {
                mile_cnt = cdiv(x, 30);
            }
            if(x % 60 == 0) {
                juice_cnt = x / 60 + 1;
            }else {
                juice_cnt = cdiv(x, 60);
            }
            mile += mile_cnt * 10;
            juice += juice_cnt * 15;
        }
        if(mile < juice) {
            cout << "Mile " << mile;
        }else if(juice < mile) {
            cout << "Juice " << juice;
        }else {
            cout << "Mile Juice " << juice;
        }
        cout << "\n";
    }
}

