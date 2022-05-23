#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
int p[MAXN];
int rp[MAXN];
int a[MAXN];
int dp[MAXN][20];
int last[MAXN];
int ls[MAXN];

int n, m, q;

int jump(int i, int x) {
    if (x == 0)
        return i;
    int ret = i;
    for (int k = 0; k < 20; ++k) {
        if (x & (1 << k)) {
            ret = dp[ret][k];
            if (ret == 0)
                return ret;
        }
    }
    return ret;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i){
        cin >> p[i];
        rp[p[i]] = i - 1;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(last, 0, sizeof(last));
    memset(ls, 0, sizeof(ls));
    int l = 0;
    last[a[1]] = 1;
    l = (n == 1) ? 1 : 0;
    ls[1] = l;
    for (int i = 2; i <= m; ++i) {
        dp[i][0] = last[p[(rp[a[i]] + n - 1) % n + 1]];
        for (int k = 1; k < 20; ++k) {
            if (dp[i][k-1] && dp[dp[i][k-1]][k-1]) {
                dp[i][k] = dp[dp[i][k-1]][k-1];
            }
        }
        l = max(l, jump(i, n - 1));
        ls[i] = l;
        last[a[i]] = i;
        // cout << "ls[" << i << "] = " << ls[i] << endl;
    }
    int li, ri;
    for (int i = 1; i <= q; ++i) {
        cin >> li >> ri;
        if (ls[ri] && li <= ls[ri]) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}