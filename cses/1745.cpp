#include <bits/stdc++.h>


using namespace std;
int n;
int x[1010];
bool can[100010];
int main() {
    cin >> n;
    memset(can, 0, sizeof(can));
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    can[0] = true;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum; j >= 0; --j) {
            if (can[j])
                can[j+x[i]] = true;
        }
        sum += x[i];
    }
    int ans = 0;
    for (int i = 1; i <= sum; ++i) {
        if (can[i])
            ++ans;
    }
    cout << ans << endl;
    for (int i = 1; i <= sum; ++i) {
        if (can[i])
            cout << i << " ";
    }
}
