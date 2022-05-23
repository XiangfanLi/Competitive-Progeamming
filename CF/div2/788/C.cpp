#include <bits/stdc++.h>

using namespace std;

int t, n;

#define MAXN 100010
#define ll long long
ll MOD = (ll)(1e9+7);

int a[MAXN], b[MAXN], d[MAXN];
int ar[MAXN], br[MAXN];

bool tryput(int i, char choice) {
	d[i] = -1;
	if (choice == 'a') {
		if (d[br[a[i]]] == a[i] || d[ar[b[i]]] > 0 && d[ar[b[i]]] != b[i]) {
			return false;
		}
		if (d[ar[b[i]]] == b[i]) {
			return true;
		}
		d[i] = a[i];
		if (tryput(ar[b[i]], 'a')) {
			d[i] = -1;
			return true;
		} else {
			d[i] = -1;
			return false;
		}
	} else {
		if (d[ar[b[i]]] == b[i] || d[br[a[i]]] > 0 && d[br[a[i]]] != a[i]) {
			return false;
		}
		if (d[br[a[i]]] == a[i]) {
			return true;
		}
		d[i] = b[i];
		if (tryput(br[a[i]], 'b')) {
			d[i] = -1;
			return true;
		} else {
			d[i] = -1;
			return false;
		}
	}
}


int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			ar[a[i]] = i;
		}
		for (int i = 1; i <= n; ++i) {
			cin >> b[i];
			br[b[i]] = i;
		}
		for (int i = 1; i <= n; ++i) {
			cin >> d[i];
			// cout << "d[" << i << "] = " << d[i] << endl;
		}
		ll ans = 1;
		for (int i = 1; i <= n; ++i) {
			if (d[i] == 0) {
				if (a[i] == b[i]) {
					continue;
				}
				// cout << "i = " << i << endl;
				ll cc = 0;
				if (tryput(i, 'a')) {
					++cc;
				}
				if (tryput(i, 'b')) {
					++cc;
				}
				ans = ans * cc;
				ans = ans % MOD;
			}
		}
		cout << ans << endl;
	}
}