#include <bits/stdc++.h>

using namespace std;
int p;

constexpr int Pow2(int n) {
	int ret = 1;
	while(n--) {
		ret *= 2;
	}
	return ret;
}

constexpr int MAXN = Pow2(19) + 10;

vector<int> neigh[MAXN];
int t;
int n;
int u, v;
int low, high;
int edges[MAXN][2];
int val[MAXN];

void dfs(int u, int p, bool dep) {
	if (u == 1) {
		val[u] = n;
	} else {
		if (dep) {
			val[u] = high;
			++high;
		} else {
			val[u] = low;
			++low;
		}
	}
	for (int ei: neigh[u]) {
		int v = (edges[ei][0] == u) ? edges[ei][1] : edges[ei][0];
		if (v == p) {
			continue;
		}
		if (dep) {
			val[ei+n] = high;
			++high;
		} else {
			val[ei+n] = low;
			++low;
		}
		dfs(v, u, !dep);
	}
	return;
}

int main() {
	cin >> t;
	while(t--) {
		cin >> p;
		n = Pow2(p);
		for (int i = 1; i <= n; ++i) {
			neigh[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			cin >> edges[i][0] >> edges[i][1];
			neigh[edges[i][0]].push_back(i);
			neigh[edges[i][1]].push_back(i);
		}
		low = 1;
		high = n + 1;
		dfs(1, 0, true);
		cout << 1 << endl;
		for (int i = 1; i <= n; ++i) {
			cout << val[i] << " ";
		}
		cout << endl;
		for (int i = 1; i < n; ++i) {
			cout << val[n+i] << " ";
		}
		cout << endl;
	}
}