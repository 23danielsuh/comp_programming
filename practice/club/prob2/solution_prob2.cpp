#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin>>T;
    while (T--){
        int N, D; 
        cin >> N >> D;
        vector<int> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for(int day = 0; day < D; day++) {
            for(int i = 1; i < N; i++) {
                if(A[i] > 0) { 
                    A[i]--;
                    A[i - 1]++;
                    break;
                }
            }
        }
        cout << A[0] << " ";
    }
}
