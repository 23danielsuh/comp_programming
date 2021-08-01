#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        int N; cin >> N;
        if(!N) break;
        vector<string> A(N - 1); for(auto &x : A) cin >> x;
        string cur = "+x";
        for(int i = 0; i < N - 1; i++) {
            if(A[i] == "No") {
                continue;
            }
            if(cur == "+x") {
                cur = A[i];
            }else if(cur == "-x") {
                if(A[i] == "+y") {
                    cur = "-y";
                }else if(A[i] == "-y") {
                    cur = "+y";
                }else if(A[i] == "+z") {
                    cur = "-z";
                }else {
                    cur = "+z";
                }
            }else if(cur == "+y") {
                if(A[i] == "+y") {
                    cur = "-x";
                }else if(A[i] == "-y") {
                    cur = "+x";
                }else if(A[i] == "+z") {
                    cur = "+y";
                }else {
                    cur = "+y";
                }
            }else if(cur == "-y") {
                if(A[i] == "+y") {
                    cur = "+x";
                }else if(A[i] == "-y") {
                    cur = "-x";
                }else if(A[i] == "+z") {
                    cur = "-y";
                }else {
                    cur = "-y";
                }
            }else if(cur == "+z") {
                if(A[i] == "+y") {
                    cur = "+z";
                }else if(A[i] == "-y") {
                    cur = "+z";
                }else if(A[i] == "+z") {
                    cur = "-x";
                }else {
                    cur = "+x";
                }
            }else if(cur == "-z") {
                if(A[i] == "+y") {
                    cur = "-z";
                }else if(A[i] == "-y") {
                    cur = "-z";
                }else if(A[i] == "+z") {
                    cur = "+x";
                }else {
                    cur = "-x";
                }
            }
            //cout << cur << " ";
        }
        cout << cur << "\n";
    }
}

