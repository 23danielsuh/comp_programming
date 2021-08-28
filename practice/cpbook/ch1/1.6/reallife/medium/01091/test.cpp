#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int A = 20, B = 200;
    pair<double, double> range1 = make_pair((double) A * 0.95, (double) A * 1.05);
    pair<double, double> range2 = make_pair((double) B * 0.95, (double) B * 1.05);
    cout << fixed << setprecision(5);
    cout << range1.first << " " << range1.second << "\n";
    cout << range2.first << " " << range2.second << "\n";
}

