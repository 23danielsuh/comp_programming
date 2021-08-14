#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    set<int> a, b;
    a.insert(1);
    a.insert(3);
    b.insert(2);
    cout << *b.find(3);
}

