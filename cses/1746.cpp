#include <bits/stdc++.h>

using namespace std;

int n, m;
int x[100010];
#define ll long long
const ll MOD = (ll)(1e9+7);
ll dp[100010][102];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    memset(dp, 0, sizeof(dp));
    if (x[1] == 0) {
        for (int j = 1; j <= m; ++j) {
            dp[1][j] = 1;
        }
    } else {
        dp[1][x[1]] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1] + dp[i-1][j]) % MOD;
            }
        } else {
            dp[i][x[i]] = (dp[i-1][x[i]-1] + dp[i-1][x[i]+1] + dp[i-1][x[i]]) % MOD;
        }
    }
    ll ans = 0;
    if (x[n] == 0) {
        for (int j = 1; j <= m; ++j)
            ans = (ans + dp[n][j]) % MOD;
    } else {
        ans = dp[n][x[n]];
    }   
    cout << ans;
}
