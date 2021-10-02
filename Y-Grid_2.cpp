#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define f first
#define s second
#define INF 1000000007
ll fi[3000001];
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll InverseEuler(ll n, ll MOD)
{
 return binpow(n,MOD-2,MOD);
}
ll fin[300001];
ll C(ll n, ll r, ll MOD)
{
    if(r!=0 && r!=n)
 return (fi[n]*((fin[r] * fin[n-r]) % MOD)) % MOD;
   else
    return 1ll;
}
void solve()
{
    fi[0] = 1ll;
    for(ll i = 1 ; i <= 300000ll ; i++)
        fi[i] = (fi[i-1]*i)%mod;
    for(ll i=1;i<=300000;i++)
        fin[i]=InverseEuler(fi[i],mod);
   ll h,w,n;
   cin>>h>>w>>n;
   pair<ll,ll> ar[n+1];
   for(int x=0;x<n;x++)
    cin>>ar[x].f>>ar[x].s;
    ar[n]={h,w};
    sort(ar,ar+n+1);
    ll dp[n+1]={0};
    for(int x=0;x<=n;x++)
    {   dp[x]=C(ar[x].f+ar[x].s-2,ar[x].f-1,INF);
        for(int y=0;y<x;y++)
        {
           if(ar[y].f<=ar[x].f && ar[y].s<=ar[x].s)
            {
                 dp[x]-=(dp[y]*C(ar[x].f+ar[x].s-(ar[y].f+ar[y].s),ar[x].s-ar[y].s,INF))%mod;
                dp[x]=(mod+dp[x])%mod;
            }
        }
    }
    cout<<dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
}

