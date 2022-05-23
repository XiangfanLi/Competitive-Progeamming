#include <bits/stdc++.h>

using namespace std;

int T, N;
string W;
#define ll long long
const ll MOD = (ll)(1e9+7);
const ll INF = (ll)(1e10);



int main() {
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> N;
		cin >> W;
		ll diff = 0;
		ll l = 0, r = 0;
		ll ans = 0;
		ll pre = 0;
		int li = -1;
		for(int i = 0; i < N; ++i) {
			if (W[i] == 'F') {
					
			} else if (W[i] == 'X') {
				l = min(l, r + 1);
				r = INF;
			} else {
				r = min(r, l + 1);
				l = INF;
			}
			if(li >= 0) {
				if(W[i] != 'F' && W[li] != W[i]) {
					diff += (i - li);
					diff %= MOD;
				}
			}
			ans += ((i+1)* min(l, r) - pre);
			ans -= diff;
			ans = ((ans % MOD) + MOD) % MOD;
			cout << "ans [" << i << "] = " << ans << endl;
			
			pre += min(l, r);
			pre %= MOD;
			if(W[i] != 'F')
				li = i;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}

