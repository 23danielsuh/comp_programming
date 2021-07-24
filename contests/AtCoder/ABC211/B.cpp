
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    set<string> st;
    for(int i = 0; i < 4; i++) {
        string temp; cin >> temp;
        st.insert(temp);
    }
    if(st.size() == 4) {
        cout << "Yes" << "\n";
    }else {
        cout << "No" << "\n";
    }
}
