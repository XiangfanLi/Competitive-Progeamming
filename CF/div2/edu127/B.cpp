#include <bits/stdc++.h>


using namespace std;


#define MAXN 200010

int x[MAXN];
bool dp[MAXN][3]; // i-1, i, i+1
int t, n;

int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		dp[1][0] = true;
		dp[1][1] = true;
		dp[1][2] = true;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[i][j] = false;
				for (int k = 0; k < 3; ++k) {
					if (dp[i-1][k] && x[i-1] + k - 1 + 1 == x[i] + j - 1) {
						dp[i][j] = true;
						break;
					}
				}
			}
		}
		if (dp[n][0] || dp[n][1] || dp[n][2]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}