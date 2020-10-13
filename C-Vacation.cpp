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
        ll a[n][3];
        for(ll x=0; x<n; x++){
            cin>>a[x][0]>>a[x][1]>>a[x][2];
        }
        ll dp[n][3];
        dp[0][0]=a[0][0];
        dp[0][1]=a[0][1];
        dp[0][2]=a[0][2];
        for(ll x=1; x<n; x++){
            dp[x][0]=a[x][0]+max(dp[x-1][1],dp[x-1][2]);
            dp[x][1]=a[x][1]+max(dp[x-1][0],dp[x-1][2]);
            dp[x][2]=a[x][2]+max(dp[x-1][1],dp[x-1][0]);
        }
        cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<"\n";
    }
    return 0;
}
