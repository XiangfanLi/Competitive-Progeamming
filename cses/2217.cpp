#include <bits/stdc++.h>


using namespace std;

int n, m;
int x[200010];
int idx[200010];
pair<int, int> ops[200010];

int switch_near(int i, int j) {
	int ret = 0;
	if (i > j) {
		swap(i, j);
	}
	if (i > 1 && idx[i] < idx[i-1])
		++ret;
	if (j < n && idx[j] > idx[j+1])
		++ret;
	
	if (j > 1 && idx[j] < idx[j-1])
		++ret;
	if (i + 1 != j && i < n && idx[i] > idx[i+1])
		++ret;

	return ret;
}

int a, b;


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		idx[x[i]] = i;
	}

	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		ops[i] = make_pair(a, b);
	}

	int ans = 0;
	int last_idx = n+1;
	for (int i = 1; i <= n; ++i) {
		if (last_idx >= idx[i]) {
			++ans;
		}
			last_idx = idx[i];
	}
	
	for (int i = 1; i <= m; ++i) {
		int u = x[ops[i].first];
		int v = x[ops[i].second];
		int before = switch_near(u, v);
		x[ops[i].first] = v;
		x[ops[i].second] = u;
		idx[v] = ops[i].first;
		idx[u] = ops[i].second;
		int after = switch_near(u, v);
		ans = ans - before + after;
		cout << ans << endl;
	}

}