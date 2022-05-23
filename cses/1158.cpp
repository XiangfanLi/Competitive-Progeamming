#include <bits/stdc++.h>


using namespace std;

int n, x;
int h[1010];
int s[1010];
int dp[100010];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    

    memset(dp, 0, sizeof(dp));
    int ans = 0;
    int Max = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = Max; j >= 0; --j) {
            if (j + h[i] <= x) {
                Max = max(Max, j + h[i]);
                dp[j+h[i]] = max(dp[j+h[i]], dp[j] + s[i]);
                ans = max(ans, dp[j+h[i]]);
            }
        }
    }
    cout << ans;

}
