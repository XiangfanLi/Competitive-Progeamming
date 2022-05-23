#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1010;
int n;
#define ll long long
ll x;
ll a[MAXN];
map<ll, pair<int, int> > Map;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i3 = 1; i3 <= n; ++i3) {
        for (int i4 = i3 + 1; i4 <= n; ++i4) {
            ll target = x - (a[i3] + a[i4]);
            if (Map.count(target) != 0) {
                const auto& p = Map[target];
                cout << p.first << " " << p.second << " " << i3 << " " << i4 << endl;
                return 0;
            }
        }
        for (int i1 = 1; i1 < i3; ++i1) {
            Map[a[i1] + a[i3]] = make_pair(i1, i3);
        }
    }
    cout << "IMPOSSIBLE" << endl;

}