#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define rep(i,a,n) for(lli i=a;i<n;i++)
#define rrep(i,n,a) for(lli i=n;i>=a;i--)
#define vlli vector<lli>
#define mii map<int,int>
#define umii unordered_map<int,int>
lli mod=1e9+9;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
string solve(vlli a,lli n,lli k)
{
    if(n==k)
    return"Yes";
    vlli st(n);
    vlli b;
    b=a;
    sort(b.begin(),b.end());
    rep(i,0,n)
    {
        st[i]=1;
        lli pos=find(b.begin(),b.end(),a[i])-a.begin();
        if(i>0 && pos>0)
        {
            if(a[i-1]==a[pos-1])
            {
                st[i]=st[i-1]+1;
                st[i-1]=0;
            }
        }
    }
    sort(st.begin(),st.end());
    reverse(st.begin(),st.end());
    lli cnt=0;
    rep(i,0,k)
    {
        cnt+=st[i];
    }
    if(cnt>=n) return "Yes";
    return "No";
}
int main() {
    fastio();
    lli q;
    cin>>q;
    while(q--)
    {
        lli n,k;
        cin>>n>>k;
        vlli a(n);
        rep(i,0,n)
        cin>>a[i];
        cout<<solve(a,n,k)<<endl;
    }
    return 0;
}
