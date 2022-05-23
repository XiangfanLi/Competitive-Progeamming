#include <bits/stdc++.h>


using namespace std;

int n;
int x[200010];
int idx[200010];


int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		idx[x[i]] = i;
	}
	int ans = 0;
	int last_idx = n+1;
	for (int i = 1; i <= n; ++i) {
		if (last_idx >= idx[i]) {
			++ans;
		}
			last_idx = idx[i];
	}
	cout << ans;
}