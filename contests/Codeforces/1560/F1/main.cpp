#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

vector<int> k_1, k_2;
vector<vector<bool>> pos;

void gen(int n, int i, int arr[]) {
    if(i == n) {
        vector<bool> temp;
        for(int k = 0; k < n; k++) {
            temp.push_back(arr[k]);
        }
        pos.push_back(temp);
        return;
    }
    arr[i] = 0;
    gen(n, i + 1, arr);
    
    arr[i] = 1;
    gen(n, i + 1, arr);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for(int j = 1; j <= 11; j++) {
        for(char i = '1'; i <= '9'; i++) {
            string temp = "";
            for(int k = 0; k < j; k++) {
                temp += i;
            }
            k_1.push_back(stoll(temp));
        }
    }
    sort(k_1.begin(), k_1.end());
    for(char val1 = '0'; val1 <= '9'; val1++) {
        for(char val2 = '0'; val2 <= '9'; val2++) {
            if(val1 == val2) continue;
            for(int i = 1; i <= 10; i++) {
                //i is the length of the string
                int arr[i];
                pos.clear();
                gen(i, 0, arr);
                for(int x = 0; x < (int) pos.size(); x++) {
                    string temp = "";
                    for(int j = 0; j < (int) pos[x].size(); j++) {
                        if(pos[x][j]) {
                            temp += val1;
                        }else {
                            temp += val2;
                        }
                    }
                    if(to_string(stoll(temp)) != temp) {
                        continue;
                    }
                    k_2.push_back(stoll(temp));
                }
            }
        }
    }
    sort(k_2.begin(), k_2.end());
    while(T--) {
        int N, K; cin >> N >> K;
        if(K == 1) {
            cout << *lower_bound(k_1.begin(), k_1.end(), N) << "\n";
        }else {
            cout << *lower_bound(k_2.begin(), k_2.end(), N) << "\n";
        }
    }
}

