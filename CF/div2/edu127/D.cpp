#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;

int t, n, x, a[MAXN];
#define ll long long
int main() {

	cin >> t;
	while(t--) {
		cin >> n >> x;
		int Min = INT_MAX;
		int Max = INT_MIN;
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			Min = min(Min, a[i]);
			Max = max(Max, a[i]);
			if (i > 1) {
				ans += abs(a[i]-a[i-1]);
			}
		}
		int l = a[1];
		int r = a[n];

		if (1 < Min) {
			ans += min(min(l - 1, r - 1), 2 * (Min - 1));
		}

		if (x > Max) {
			ans += min(min(x - l, x - r), 2 * (x - Max));
		}


		cout << ans << endl;
	}

}