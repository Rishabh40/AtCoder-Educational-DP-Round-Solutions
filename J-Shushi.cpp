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
ll arr[301];
long double dp[301][301][301];
ll n;
long double solve(ll x, ll y, ll z) {
	if(x<0 || y<0 || z<0){
		return 0;
    }
	else if (x == 0 && y == 0 && z == 0){
		return 0;
    }
	else if (dp[x][y][z] >= 0.0){
		return dp[x][y][z];
    }
    else{
        dp[x][y][z] = ((n + x * solve(x - 1, y, z) + y * solve(x+1, y-1 , z) + z * solve(x, y+1 , z - 1)));
        dp[x][y][z]/=(x+y+z);
    }
	return dp[x][y][z];
}

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
        cin >> n;
	    ll x=0, y=0, z=0;
        for (ll i = 0; i < n; i++){	
            cin >> arr[i];
            if (arr[i] == 1)
                x++;
            else if (arr[i] == 2)
                y++;
            else if (arr[i] == 3)
                z++;
        }
        memset(dp,-1.0,sizeof(dp));
        cout<<fixed<<setprecision(20)<<solve(x,y,z)<<endl;
        mp.clear();  
        v.clear();
        //cout<<"Case #"<<c<<": "<<ans<<"\n";
        //c++;
    }
    return 0;
}