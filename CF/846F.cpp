#include <bits/stdc++.h>

const int MAXN = 1000010;
using namespace std;
#define ll long long
int n;
int a[MAXN];
vector<ll> idx[MAXN];
int main() {
    cin >> n;
    unordered_set<int> distinct;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        idx[a[i]].push_back(i);
        distinct.insert(a[i]);
    }
    double ans = 0.0;
    for (int i: distinct) {
        int m = (int)idx[i].size();
        for (int j = 0; j < m; ++j) {
            ans += 2 * ((j == m - 1) ? n - idx[i][j] + 1 : (idx[i][j+1] - idx[i][j]))
                * idx[i][j];
            ans -= 1;
        }
    }
    ans /= (ll)n * n;
    cout << std::fixed << std::setprecision(6) << ans << endl;
}