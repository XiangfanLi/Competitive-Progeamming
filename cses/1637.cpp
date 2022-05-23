#include <bits/stdc++.h>



using namespace std;
int n;
int dp[1000010];

int main() {
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int ii = i;
        dp[i] = (int)1e9;
        while (ii) {
            int d = ii % 10;
            if (d != 0) {
                dp[i] = min(dp[i], dp[i-d] + 1);
            }
            ii /= 10;
        }
    }
    cout << dp[n] << endl;
}
