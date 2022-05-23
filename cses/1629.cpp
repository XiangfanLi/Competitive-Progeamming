#include <bits/stdc++.h>

using namespace std;

int n;
#define MAXN 200010
int a, b;
vector<pair<int, int>> itvs;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b;
		itvs.push_back(make_pair(a, b));
	}
	sort(itvs.begin(), itvs.end(), [](const pair<int, int>& x, const pair<int, int>& y) -> bool {
		return x.second < y.second;
	});
	vector<pair<int, int>> v;
	for (auto& itv: itvs) {
		int idx = lower_bound(v.begin(), v.end(), make_pair(itv.first+1, -1)) - v.begin();
		int curr = (v.empty()) ? 0 : (v.back().second);
		if (idx == 0) {
			curr = max(curr, 1);
		} else {
			curr = max(curr, v[idx-1].second + 1);
		}
		v.push_back(make_pair(itv.second, curr));
	}
	cout << v.back().second << endl;

}