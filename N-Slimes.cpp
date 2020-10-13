//   Rishabh Agarwal
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef long long int ll;
const ll mod = 1e18;
const ll INF= 1e18;
const long double PI=3.1415926;

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

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

vector<ll>v;
vector<ll>::iterator it;
map<ll,ll>mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.tex", "w", stdout);
    #endif

    ll t;
    //cin>>t;
    t=1;
    //ll c=1;
    while(t--){
        ll n;
        cin>>n;
        for(ll x=0; x<n; x++){
            ll y;
            cin>>y;
            v.push_back(y);
        }
        ll sum[n+1];
        memset(sum,0,sizeof(sum));
        for(ll x=0; x<n; x++){
            sum[x+1]=sum[x]+v[x];
        }
        ll dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(ll x=2; x<=n; x++){
            for(ll l=1; l+x-1<=n; l++){
                ll r=l+x-1;
                dp[l][r]=1e18;
                for(ll m=l; m<r; m++){
                    dp[l][r]=min(dp[l][r],dp[l][m]+dp[m+1][r]);
                }
                dp[l][r]+=sum[r]-sum[l-1];
            }
        }
        cout<<dp[1][n]<<"\n";
        mp.clear();  
        v.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}