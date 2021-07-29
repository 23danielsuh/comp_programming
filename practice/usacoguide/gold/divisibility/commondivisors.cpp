#include <iostream>

using namespace std;
typedef long long ll;

int mp[int(1e6 + 5)];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int temp; cin >> temp;
        for(int j = 1; j * j <= temp; j++) {
            if(temp % j == 0) {
                mp[j]++;
                if(j != temp / j) mp[temp / j]++;
            }
        }
    }
    for(int i = 1000000; i >= 1; i--) {
        if(mp[i] > 1) {
            cout << i << "\n";
            return 0;
        }
    }
}

