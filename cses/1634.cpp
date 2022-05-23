#include <bits/stdc++.h>


using namespace std;
int n, x;
int c[110];
int dp[1000010];
const int INF = (int)(1e9);

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        dp[i] = INF;
        for (int j = 1; j <= n; ++j) {
            if (i >= c[j]) {
                dp[i] = min(dp[i], dp[i-c[j]] + 1);
            }
        }
    }
    cout << ((dp[x] >= INF) ? -1 : dp[x]) << endl;
}
