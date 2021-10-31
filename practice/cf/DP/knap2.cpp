#include <bits/stdc++.h>

using namespace std;
#define int int64_t

const int N = 505;

int n;
vector<int> a(N);
int dp[N][N];

int calc(int l, int r){	
	int &res = dp[l][r];
	if(res != -1) return res;
	
	if(l > r) return res = 0;
	if(l == r) return res = 1;
    
	res = 1 + calc(l + 1, r);
	for(int i = l + 1; i <= r; ++ i)
		if(a[l] == a[i])
			res = min(res, calc(l + 1, i - 1) + calc(i, r));
	return res;
}

int32_t main(){
	cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
	memset(dp, -1, sizeof dp);
	cout << calc(0, n - 1);
	return 0;
}