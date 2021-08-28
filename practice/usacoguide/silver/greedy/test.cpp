#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    multiset<int> st;
    st.insert(3);
    cout << *st.upper_bound(5);
}

