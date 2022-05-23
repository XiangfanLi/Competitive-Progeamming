#include <bits/stdc++.h>


using namespace std;
#define ll long long
const ll MOD = (ll)(1e9+7);
int n;
char grid[1010][1010];
ll dp[1010][1010];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        scanf("%s", grid[i]);
    }
    memset(dp, 0, sizeof(dp));
    if (grid[0][0] == '*') {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*')
                continue;
            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[n-1][n-1];
}
