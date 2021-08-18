#include<bits/stdc++.h>
using namespace std;
//#define int long long 
int t, n, k;
int f()
{
	int cnt = to_string(n).size();
	if(k == 1)
	{
		int ans = 0;
		for(int i = 0; i < cnt; i++)
			ans = ans * 10 + 1;
		for(int i = 0; i < 10; i++)
			if(i * ans >= n)
				return i * ans;
	}
	int ans = 2e9;
	int s = to_string(n)[0] - '0';
	//for(int i = 0; i <= cnt; i++)
	for(int i = 0; i <= 1 << cnt; i++)
		for(int j = s; j < s+1; j++)
			for(int k = 0, x, m, cur; k < 10; k++)
			{
			//	for(x = cur = 0; x < cnt; x++)
			//		cur = cur * 10 + (x <= i ? j : k);
				for(m = i, x = cur = 0; x < cnt; x++, m/=2)
					cur = cur * 10 + (m%2 ? j : k);
				if(cur >= n)
					ans = min(cur, ans);			
			}
	return ans;
}
signed main()
{
	for(cin >> t; t--; )
	{
		cin >> n >> k;
		cout << f() << "\n";
	}
}
