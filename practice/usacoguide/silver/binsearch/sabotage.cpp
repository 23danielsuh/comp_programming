#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, sum = 0;
vector<int> A;

bool check(double avg) {
    
}

double bin_search() {
    double lo = 1, hi = 10000;
    while(round(lo * 10000.0) < round(hi * 10000.0)) {
        double mid = (lo + hi) / 2;
        if(check(mid)) {
            hi = mid;
        }else {
            lo = mid + 1;
        }
    }
    return lo;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; A.resize(N); for(auto &x : A) cin >> x;
    cout << check(2667);
    //cout << bin_search() << "\n";
}

