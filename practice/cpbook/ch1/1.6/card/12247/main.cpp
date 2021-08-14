#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        vector<int> a, b;
        for(int i = 0; i < 3; i++) {
            int x; cin >> x;
            a.push_back(x);
        }
        for(int i = 0; i < 2; i++) {
            int x; cin >> x;
            b.push_back(x);
        }
        if(!(a[0] && a[1] && a[2] && b[0] && b[1])) return 0;
        sort(a.begin(), a.end());
        int ans = -1;
        for(int card = 1; card <= 52; card++) {
            bool flag = 0;
            for(int i = 0; i < 3; i++) {
                if(card == a[i]) {
                    flag = 1;
                }
            }
            for(int i = 0; i < 2; i++) {
                if(card == b[i]) {
                    flag = 1;
                }
            }
            if(flag) continue;
            vector<int> cur = b;
            cur.push_back(card);
            sort(cur.begin(), cur.end());
            bool lose = 0;
            do {
                do {
                    int sum = 0;
                    for(int i = 0; i < 3; i++) {
                        if(cur[i] < a[i]) {
                            sum++;
                        }
                    }
                    if(sum >= 2) {
                        lose = 1;
                        break;
                    }
                }while(next_permutation(cur.begin(), cur.end()));
            }while(next_permutation(a.begin(), a.end()));

            if(!lose) {
                ans = card;
                break;
            }
        }
        cout << ans << "\n";
    }
}

