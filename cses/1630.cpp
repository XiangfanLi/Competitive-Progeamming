#include <bits/stdc++.h>


using namespace std;

int n, a, d;
#define ll long long

int main() {
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        cin >> a >> d;
        v.push_back({a, d});
    }
    sort(v.begin() ,v.end());
    ll ans = 0;
    ll t = 0;
    for (auto p: v) {
        t += p.first;
        ans += (p.second - t);
    }
    cout << ans << endl;
}