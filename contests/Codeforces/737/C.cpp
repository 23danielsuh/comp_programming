#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define l long
#define pb push_back
#define F first
#define S second
#define all(c)  c.begin(), c.end()
#define llv vector< ll >
#define mp make_pair
#define endl "\n"
const int N = (int)998244353 ;
const int M = (int)1000000007;
 
ll int gcd(ll int a  , ll int b){
   if(b==0) return a ;
   return gcd(b , a%b) ;
}
int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    ll int t;
    cin>>t;
    for(ll int j=0;j<t;j++)
    {
        ll int n,k,count2=0,count3=0,count=0;
        cin>>n>>k;
        ll int a[n];
        for(ll int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        // sort(a,a+n);
        if(k==1)cout<<"Yes"<<endl;
        else
        {
            vector<vector<int>>x;
            int count =0,flag=1;
            vector<int>y;
            for(int i=0;i<n-1;i++)
            {
                if(a[i]+1==a[i+1])
                {
                    count++;
                    if(flag)
                    {
                        y.push_back(i);
                        flag=0;
                    }
                }
                else
                {
                    y.push_back(i);
                    x.push_back(y);
                    flag=1;
                }
            }
            vector<int>z;
            for(int i=0;i<x.size();i++)
            {
                z.push_back(x[i][1]-x[i][0]+1);
                count2+=(x[i][1]-x[i][0]+1);
 
            }
            int p=n-count2;
            if(k>=p+x.size())cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
