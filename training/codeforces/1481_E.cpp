/*
https://codeforces.com/contest/1481/problem/E
*/
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int n;
	cin>>n;
	vector<int> a(n),f(n),cf(n);
	vector<pair<int,int>> at(n,{-1,-1});
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
		f[a[i]]++;
		if(at[a[i]].first == -1)at[a[i]] = {i,i};
		at[a[i]].second = i;
	}
	vector<int> dp(n+1);

	for(int i=n-1;i>=0;i--){
		dp[i] = dp[i+1];
		cf[a[i]]++;
		if(i == at[a[i]].first)dp[i] = max(dp[i] , dp[at[a[i]].second + 1] + f[a[i]]);
		else dp[i] = max(dp[i] , cf[a[i]]);
	}

	cout << n - dp[0] << '\n';
}