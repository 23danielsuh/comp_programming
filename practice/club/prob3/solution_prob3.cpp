#include <bits/stdc++.h>

using namespace std;

const int mxN = 505;

int N;
vector<int> s(mxN);
int dp[mxN][mxN];

int recurse(int l, int r){	
	int &res = dp[l][r];
	if(res != -1) return res; //memoization step
	
	if(l > r) return res = 0;
	if(l == r) return res = 1;
    
	res = 1 + recurse(l + 1, r);
	for(int i = l + 1; i <= r; i++) {
		if(s[l] == s[i]) {
			res = min(res, recurse(l + 1, i - 1) + recurse(i, r));
        }
    }
    
	return res;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s[i];
    }
	memset(dp, -1, sizeof dp);
	cout << recurse(0, N - 1);
}
