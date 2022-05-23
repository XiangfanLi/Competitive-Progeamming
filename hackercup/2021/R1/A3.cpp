#include <bits/stdc++.h>

using namespace std;

int T, N;
string W;
#define ll long long
const ll MOD = (ll)(1e9+7);



int main() {
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> N;
		cin >> W;
		ll diff = 0;
		ll ans = 0;
		ll pre = 0;
		ll suf = 0;
		ll curr = 0;
		char fir = '#';
		char last = '#';
		ll sufn = 0, pren = 0;
		ll len = 0;
		for(int i = 0; i < N; ++i) {
			if(W[i] == 'X') {
				ll lastlen = len;
				len = (len + 1) % MOD;
				
				if(last == 'O') {
					suf += (lastlen - sufn);
					suf %= MOD;
					diff = (diff + sufn + 1) % MOD;
					curr = (curr + 1) % MOD;
				}
		
				/*ans += (len* min(l, r) - pre);
				ans %= MOD;
				ans -= diff;
				ans %= MOD;*/
				ans += suf;
				ans %= MOD;
				pre = (pre + curr) % MOD;
			} else if (W[i] == 'O') {
				ll lastlen = len;
				len = (len + 1) % MOD;
				
				if(last == 'X') {
					suf += (lastlen - sufn);
					suf %= MOD;
					diff = (diff + sufn + 1) % MOD;
					curr = (curr + 1) % MOD;
				}
				
				/*ans += (len* min(l, r) - pre);
				ans %= MOD;
				ans -= diff;
				ans %= MOD;*/
				
				ans += suf;
				ans %= MOD;
				pre = (pre + curr) % MOD;
			} else if (W[i] == 'F') {
				len = (len + 1) % MOD;
				
				suf = suf;
				
				/*ans += (len* min(l, r) - pre);
				ans %= MOD;
				ans -= diff;*/
				
				ans += suf;
				ans %= MOD;
				
				pre = (pre + curr) % MOD;
			} else {
				ll lp = curr;
				ll lastlen = len;
				ll lastpre = pre;
				ll lastsuf = suf;
				len = (len * 2) % MOD;
				
				bool swt = (last == 'X' && fir == 'O') || (last == 'O' && fir == 'X');
				pre = (pre + lp * lastlen + pre) % MOD;
				if (swt) {
					pre = (pre + (lastlen - pren)) % MOD;
				}
				curr = (2 * curr) % MOD;
				if(swt) {
					curr = (curr + 1) % MOD;
				}
				
				suf = (suf + lp * lastlen + suf) % MOD;
				if (swt) {
					suf = (suf + (lastlen - sufn)) % MOD;
				}
				ans = (ans * 2) % MOD;
				ans = (ans + (lastpre + lastsuf) * lastlen) % MOD;
				if (swt) {
					ans = (ans + (lastlen - sufn) * (lastlen - pren)) % MOD;
				}
				diff = (diff * 2) % MOD;
				if(swt) {
					diff = (diff + pren + sufn + 1) % MOD;
				}
			}
			ans = ((ans % MOD) + MOD) % MOD;
			
			if (fir == '#' && (W[i] == 'O' || W[i] == 'X')) {
				fir = W[i];
				pren = len - 1;
			}
			if (W[i] == 'O' || W[i] == 'X') {
				last = W[i];
				sufn = 0;
			}
			if (W[i] == 'F' && last != '#') {
				++sufn;
			}
			/*
			cout << "------ i = " << i << endl;
			cout << "pre = " << pre << endl;
			cout << "suf = " << suf << endl;
			cout << "diff = " << diff << endl;
			cout << "len = " << len << endl;
			cout << "ans = " << ans << endl;
			*/
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}

