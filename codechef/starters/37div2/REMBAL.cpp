#include <bits/stdc++.h>


using namespace std;
int T;
#define MAXN 2000010
// string S;
int dp[MAXN];
char S[MAXN];

int main() {
	cin >> T;
	while(T--) {
		scanf("%s", S);
		int n = strlen(S);
		dp[0] = 0;
		for (int i = 1; i < n; ++i) {
			int j = i - 1 - dp[i-1];
			if (S[i] == '(') {
				dp[i] = 0;
			} else {
				if (j >= 0 && S[j] != S[i]) {
					dp[i] = dp[i-1] + 2;
					if (j > 0) {
						dp[i] += dp[j-1];
					}
				} else {
					dp[i] = 0;
				}
			}
		}

		int i = n - 1;
		int ans1 = n;
		int ans2 = 0;
		while (i >= 0) {
			if (dp[i] > 0) {
				++ans2;
				ans1 -= dp[i];
				i -= dp[i];
			} else {
				--i;
			}
		}
		// for (int i = 0; i < n; ++i) {
		// 	cout << "dp[" << i << "] = " << dp[i] << endl;
		// }
		cout << ans1 << " " << ans2 << endl;
	}
}