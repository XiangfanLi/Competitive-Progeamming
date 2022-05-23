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
    dp[0] = 1;
    for (int i = 1; i <= x; ++i) {
        dp[i] = 0;
        for (int j = 1; j <= n; ++j) {
            if (i >= c[j]) {
                dp[i] = (dp[i] + dp[i-c[j]]) % MOD;
            }
        }
    }
    cout << dp[x] << endl;
}
