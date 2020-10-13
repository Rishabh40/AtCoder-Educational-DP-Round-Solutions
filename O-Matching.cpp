//   Rishabh Agarwal
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef long long int ll;
const ll mod = 1e9+7;
const ll INF= 1e18;
const long double PI=3.1415926;

ll power(ll a,ll b){
    if(b==0)
        return 1;
    ll temp=power(a,b/2)%mod;
    if(b%2==0){
        return (temp*temp)%mod;
    }
    else{
        return ((a*temp)%mod*temp)%mod;
    }
}

ll gcd(ll a, ll b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 

vector<ll>v;
vector<ll>::iterator it;
map<ll,ll>mp;

int main(){
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
        ll arr[n][n];
        for(ll x=0; x<n; x++){
            for(ll y=0; y<n; y++){
                cin>>arr[x][y];
            }
        }
        ll dp[1<<n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(ll x=1; x<(1<<n); x++){
            ll count=__builtin_popcount(x);
            //cout<<count<<"\n";
            for(ll y=0; y<n; y++){
                if(arr[count-1][y]==1&&(x&(1<<y))!=0){
                    dp[x]+=dp[x-(1<<y)];
                    dp[x]%=mod;
                }
            }
        }
        cout<<dp[(1<<n) -1]<<"\n";
        mp.clear();  
        v.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}