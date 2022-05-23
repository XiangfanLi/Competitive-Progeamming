#include <bits/stdc++.h>

using namespace std;

int t, n, k, x, y;
const int MAXN = 200010;
int a[MAXN];
vector<int> neighs[MAXN];
bool K[MAXN];
int dep_y;

int dfs(int u, int p, int dep) {
	bool has = false;
	int ret = 0;
	for (int v: neighs[u]) {
		if (v == p)
			continue;
		int sub = dfs(v, u, dep+1);
		if (sub == 0) {
			if (K[v]) {
				ret += 2;
			}
		} else {
			ret += sub + 2;
		}
	}
	if (u == y) {
		dep_y = dep;
	}
	return ret;
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cin >> x >> y;
		for(int i = 1; i <= n; ++i) {
			neighs[i].clear();
			K[i] = false;
		}
		for (int i = 1; i <= k; ++i) {
			cin >> a[i];
			K[a[i]] = true;
		}
		K[y] = true;
		int u, v;
		for (int i = 1; i < n; ++i) {
			cin >> u >> v;
			neighs[u].push_back(v);
			neighs[v].push_back(u);
		}
		int ans = dfs(x, 0, 0);
		ans -= dep_y;
		cout << ans << endl;
	}
}