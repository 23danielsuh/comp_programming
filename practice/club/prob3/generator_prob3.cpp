#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rand(ll a, ll b) {
    return a + rand() % (b - a + 1LL);
}

int32_t main(int argc, char* argv[]) {
    srand(atoi(argv[1])); 
    ll t = 100;
    cout << t << "\n";
    while(t--) {
        ll n = rand(1, 100), d = rand(1, 100);
        printf("%d\n", n);
        for(ll i = 0; i < n; ++i) {
            ll x;
            x = rand(1, 10000000000);
            printf("%d ", x);
        }
        puts("");
    }
}
 