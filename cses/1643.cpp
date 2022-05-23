#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;
#define ll long long
ll x[MAXN];
ll l[MAXN];
ll r[MAXN];
int n;
int main() {
	cin >> n;
	ll total = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		total += x[i];
	}
	l[0] = (ll)(0);
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += x[i];
		l[i] = min(l[i-1], sum);
	}
	sum = 0;
	r[n+1] = (ll)(0);
	for (int i = n; i >= 1; --i) {
		sum += x[i];
		r[i] = min(r[i+1], sum);
	}
	ll ans = -(ll)(1e9+10);
	for(int i = 0; i < n; ++i) {
		ans = max(ans, total - l[i] - r[i+2]);
	}
	cout << ans;
}