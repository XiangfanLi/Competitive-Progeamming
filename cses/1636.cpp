#include <bits/stdc++.h>


using namespace std;
int n, x;
int c[110];
#define ll long long
ll dp[1000010];
const int INF = (int)(1e9);
const ll MOD = (ll)(1e9+7);

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    sort(c+1, c+n+1);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= x; ++i) {
        if (i >= c[k]) {
            dp[i] = (dp[i] + dp[i-c[k]]) % MOD;
        }
    }
    }
    cout << dp[x] << endl;
}
