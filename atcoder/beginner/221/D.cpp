#include <bits/stdc++.h>


using namespace std;
const int MAXN = 200010;
int N;
int A[MAXN], B[MAXN];


int main() {
    cin >> N;
    vector<pair<int, bool> > v;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i] >> B[i];
        v.push_back(make_pair(A[i], true));
        v.push_back(make_pair(A[i] + B[i], false));
    }
    vector<int> ans(N+1, 0);
    sort(v.begin(), v.end());
    int last = -1;
    int overlap = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        if (i > 0 && v[i].first != v[i-1].first) {
                ans[overlap] += (v[i].first - v[i-1].first);
        }
        if (!v[i].second) {
            --overlap;
        } else {
            ++overlap;
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << ans[i] << " ";
}