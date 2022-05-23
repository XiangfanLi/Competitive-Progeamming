#include <bits/stdc++.h>

using namespace std;

int n, a, b;

const int MAXN = 200010;
int l[MAXN];
int r[MAXN];
int ans[MAXN];

int main() {
    cin >> n;
    vector<tuple<int, int, int> > v;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        v.push_back({a, b, i});
    }
    sort(v.begin(), v.end());
    priority_queue<pair<int, int>> q;
    q.push({-0, 1});
    int k = 1;
    for (int i = 0; i < n; ++i) {
        if (q.empty() || -q.top().first >= std::get<0>(v[i])) {
            q.push({-std::get<1>(v[i]), ++k});
            ans[std::get<2>(v[i])] = k;
        } else {
            auto p = q.top();
            q.pop();
            q.push({-std::get<1>(v[i]), p.second});
            ans[std::get<2>(v[i])] = p.second;
        }
    }
    cout << k << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
}