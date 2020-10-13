//This is the Property of Rishabh Agarwal
#include <bits/stdc++.h>
#define F first
#define S second
#define MAX 10000003
using namespace std;

typedef long long int ll;
const ll mod = 1e9+7;
ll power(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll temp=power(a,b/2)%mod;
    if(b%2==0){
        return (temp*temp)%mod;
    }
    else{
        return ((a*temp)%mod*temp)%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    //cin>>t;
    t=1;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        a[0]=0;
        for(ll x=0; x<n; x++){
            cin>>a[x];
        }
        ll dp[n];
        dp[0]=0;
        dp[1]=abs(a[1]-a[0]);
        for(ll x=2; x<n; x++){
            dp[x]=min(dp[x-1]+abs(a[x]-a[x-1]),dp[x-2]+abs(a[x]-a[x-2]));
        }
        cout<<dp[n-1]<<"\n";
    }
    return 0;
}
