#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, T; cin >> N >> T;
    vector<int> A(N); for(auto &x : A) cin >> x;
    switch(T) {
        case 1: {
            cout << 7 << "\n";
            break;
        }
        case 2: {
            if(A[0] > A[1]) {
                cout << "Bigger\n";
            }else if(A[0] == A[1]) {
                cout << "Equal\n";
            }else {
                cout << "Smaller\n";
            }
            break;
        }
        case 3: {
            cout << max(min(A[0], A[1]), min(max(A[0], A[1]), A[2])) << "\n";
            break;
        }
        case 4: {
            int sum = 0;
            cout << accumulate(A.begin(), A.end(), sum);
            break;
        }
        case 5: {
            int sum = 0;
            for(int i = 0; i < N; i++) {
                if(!(A[i] & 1)) {
                    sum += A[i];
                }
            }
            cout << sum << "\n";
            break;
        }
        case 6: {
            for(int i = 0; i < N; i++) {
                cout << char((A[i] % 26) + 'a');
            }
            break;
        }
        case 7: {
            int i = 0;
            vector<bool> visited(N);
            fill(visited.begin(), visited.end(), 0);
            visited[0] = true;
            while(true) {
                i = A[i];
                if(i < 0 || i >= N) {
                    cout << "Out\n";
                    break;
                }else if(i == N - 1) {
                    cout << "Done\n";
                    break;
                }
                if(visited[i]) {
                    cout << "Cyclic\n";
                    break;
                }
                visited[i] = true;
            }
            break;
        }
    }
}

