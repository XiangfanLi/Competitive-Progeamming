#include <bits/stdc++.h>


using namespace std;

#define ll long long
int T, N;
ll C[60];
vector<int> neighs[60];
ll best[60];


void dfs(int u, int p)
{
	ll Max = 0;
	for(int v: neighs[u]) {
		if(v == p)
			continue;
		dfs(v, u);
		Max = max(Max, best[v]);
	}
	Max += C[u];
	best[u] = Max;
	return;
}



int main() {
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> N;
		for(int i = 1; i <= N; ++i) {
			cin >> C[i];
			neighs[i].clear();	
		}
		int A, B;
		for(int i = 1; i < N; ++i)
		{
			cin >> A >> B;
			neighs[A].push_back(B);
			neighs[B].push_back(A);
		}
		ll ans;
		dfs(1, 0);
		if((int)neighs[1].size() <= 1) {
			ans = best[1];
		} else {
			vector<ll> bs;
			for(int v: neighs[1]) {
				bs.push_back(best[v]);
			}
			sort(bs.begin(), bs.end());
			ans = C[1] + bs[(int)bs.size()-1] + bs[(int)bs.size()-2];
		}
		std::cout << "Case #" << t << ": " << ans << std::endl;
	}
}
