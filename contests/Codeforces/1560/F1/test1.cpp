#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gen(int n, int i, vector<int> arr) {
    if(i == n - 1) {
        vector<bool> temp;
        for(int k = 0; k < n; k++) {
            //temp.push_back(arr[k]);
            cout << arr[k] << " ";
        }
        cout << "\n";
    }
    arr[i] = 0;
    gen(n, i + 1, arr);
    
    arr[i] = 1;
    gen(n, i + 1, arr);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n = 5; cin >> n;
    vector<int> arr(n);
    gen(5, 0, arr);
}

