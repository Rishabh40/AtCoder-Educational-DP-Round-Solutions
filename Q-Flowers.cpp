#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

const int N = (int) 2e5 + 5; 

int n; 
int h[N], a[N]; 
ll ft[N], dp[N];

void update(int pos, ll val) {
	while (pos <= n) {
		ft[pos] = max(ft[pos], val);  
		
		pos += (pos & (-pos)); 
	}	
}

ll getMax(int pos) {
	ll res = 0; 
	
	while (pos > 0) {
		res = max(res, ft[pos]); 
		
		pos -= (pos & (-pos));
	}
	
	return res; 
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; 
	
	for (int i = 1; i <= n; i++) cin >> h[i]; 
	for (int i = 1; i <= n; i++) cin >> a[i]; 
	
	ll res = 0; 
	
	for (int i = 1; i <= n; i++) {
		dp[i] = getMax(h[i] - 1) + a[i]; 
		
		update(h[i], dp[i]); 
		
		res = max(res, dp[i]); 
	}
	
	cout << res; 
}

