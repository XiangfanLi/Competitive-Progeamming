#include <bits/stdc++.h>


using namespace std;

const int MAXN = 200010;
#define ll long long

int t, n, x, a[MAXN];
int days[MAXN];

ll calcDays(ll sum, ll step, ll x) {
	if (sum > x) {
		return 0;
	}
	return 1 + (x - sum) / step;
}

int main() {

	cin >> t;
	while(t--) {
		cin >> n >> x;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		sort(a+1, a+n+1);
		ll pfx = 0;
		for (int i = 1; i <= n; ++i) {
			pfx += a[i];
			days[i] = calcDays(pfx, i, x);
		}
		ll ans = 0;
		for (int i = n; i >= 1; --i) {
			ans += days[i];
		}	
		cout << ans << endl;
	}	

}