#include <bits/stdc++.h>
using namespace std;

int N,D,a[105];

int main(){
    int T; cin>>T;
    while (T--){
        cin>>N>>D;
        for (int i=1;i<=N;i++)
            cin>>a[i];
        while (D--){ //loop over D days
            for (int i=2;i<=N;i++)
	if (a[i]>0){ //move closest haybale over
	    a[i]--;
	    a[i-1]++;
	    break;
	}
        }
        cout<<a[1]<<endl;
    }
}