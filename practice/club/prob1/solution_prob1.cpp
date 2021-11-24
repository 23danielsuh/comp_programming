#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        int N; cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int mn = INT_MAX, index = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] < mn) {
                mn = A[i];
                index = i;
            }
        }
        cout << index + 1 << " ";
    }
}
