//   Rishabh Agarwal
#include <bits/stdc++.h>
#define F first
#define S second
#define MAX 10000003
using namespace std;

typedef long long int ll;
const ll mod = 1e9+7;
const ll INF= 1e18;
long double PI=3.1415926;

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

void primeFactors(ll n)  
{  
    while (n % 2 == 0)  
    {  
        mp[2]++;
        n = n/2;  
    }  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            mp[i]++;
            n = n/i;  
        }  
    }  
    if (n > 2){ 
        mp[n]++; 
    } 
}  

ll dp[3000][3000];

ll dp1(ll s,ll e,ll a[]){
    if(s>e){
        return 0;
    }
    else if(dp[s][e]!=-1){
        return dp[s][e];
    }
    else{
        dp[s][e] = max(a[s]-dp1(s+1,e,a),a[e]-dp1(s,e-1,a));
        return dp[s][e];
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
    //ll c=1;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll x=0; x<n; x++){
            cin>>a[x];
        }
        memset(dp,-1,sizeof(dp));
        cout<<dp1(0,n-1,a)<<"\n";
        mp.clear();  
        v.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}