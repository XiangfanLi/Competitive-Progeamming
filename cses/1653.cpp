#include <bits/stdc++.h>


using namespace std;
int n;
int x;
int w[22];
pair<int, int> dp[(1<<20)+10];
vector<int> rides_to_keys[22];
#define ll long long


int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    dp[0] = make_pair(1 ,0);
    for (int key = 1; key < (1 << n); ++key) {
        pair<int, int> p = {n+1, 0};
        for (int i = 1; i <= n; ++i) {
            int kk = 1 << (i - 1);
            if ((key | kk) == key) {
                auto p2 = dp[key ^ kk];
                if (p2.second + w[i] <= x) {
                    p = min(p, {p2.first, p2.second+w[i]});
                } else {
                    p = min(p, {p2.first+1, w[i]});
                }
            }
        }
        dp[key] = p;
    }
    cout << dp[(1<<n)-1].first << endl;
}
