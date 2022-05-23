#include <bits/stdc++.h>


using namespace std;

#define MAXN 200010
int n;
int a[MAXN];

int first_idx[MAXN];
int dp[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    vector<pair<pair<int, int>, int> > stk;
    for (int i = 1; i <= n; ++i) {
        if (first_idx[a[i]] != 0) {
            int l = first_idx[a[i]];
            while (!stk.empty() && stk.back().first.first >= l) {
                stk.pop_back();
            }
            if (stk.empty()) {
                stk.push_back(make_pair(make_pair(l, i), i - l - 1));
            } else {
                if (stk.back().first.second < l) {
                    stk.push_back(make_pair(make_pair(l, i), stk.back().second + i - l - 1));
                } else {
                    stk.push_back(make_pair(make_pair(l, i), stk.back().second + i - stk.back().first.second - 1));
                }
            //     stk.push_back(make_pair(make_pair(), ))

            //     if (l > stk.back().first.second) {
            //         stk.push_back(make_pair(make_pair(l, i), stk.back().second + (i - l - 1)));
            //     } else {
            //         if (a[stk.back().first.second] == a[i]) {
            //             stk.back().second = stk.back().second + (i - stk.back().first.second);
            //             stk.back().first.second = i;
            //         } else {
            //             pair<int, int> new_range;
            //             new_range.first = stk.back().first.first;
            //             new_range.second = i;
            //             int val = stk.back().second + (i - stk.back().first.second - 1);
            //             stk.pop_back();
            //             stk.push_back(make_pair(new_range, val));
            //         }
            //     }
            // }
            }
        } else {
            first_idx[a[i]] = i;
        }
        // cout << "dp [" << i  << "] = ";
        // if (stk.empty()) {
        //     cout << "empty";
        // } else {
        //     for (auto p : stk) {
        //         cout << "{{" << p.first.first << ", " << p.first.second << "}, " << p.second << "}, ";
        //     }
        // }
        // cout << endl;
    }
    int ans = (stk.empty()) ? 0 : (stk.back().second);
    cout << ans << endl;
}