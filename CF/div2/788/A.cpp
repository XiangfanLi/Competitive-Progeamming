#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
int t, n;
int a[MAXN];

int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int neg = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] < 0) {
				++neg;
				a[i] = -a[i];
			}
		}
		for (int i = 1; i <= neg; ++i) {
			a[i] = -a[i];
		}
		bool sorted = true;
		for (int i = 1; i < n; ++i) {
			if (a[i] > a[i+1]) {
				sorted = false;
				break;
			}
		}
		if (sorted) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}