#include <bits/stdc++.h>


using namespace std;
#define ll long long
const int MAXN = 500010;
int n;
ll a[MAXN];

int main() {
	cin >> n;
	ll total = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		total += a[i];
	}
	vector<int> ls;
	vector<int> rs;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
		if (sum * 3 == total) {
			ls.push_back(i);
		}
	}
	sum = 0;
	for (int i = n; i >= 1; --i) {
		sum += a[i];
		if (sum * 3 == total) {
			rs.push_back(n - i + 1);
		}
	}
	ll ans = 0;
	int j = (int)rs.size() - 1;
	for (int i = 0; i < (int)ls.size(); ++i) {
		int li = ls[i];
		while(j >= 0 && rs[j] + li >= n) {
			--j;
		}
		if (j >= 0) {
			ans += j + 1;
		}
	}
	cout << ans << endl;
}