#include <bits/stdc++.h>


using namespace std; 

int t, a, b;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        int ans = b - a;
        for (int i = a; i < b; ++i) {
            if ((b & i) == i) {
                ans = min(ans, i - a + 1);
                // cout << "i1 = " << i << endl;
                break;
            }
        }

        for (int i = b; ; ++i) {
            if ((i & a) == a) {
                ans = min(ans, i - b + 1);
                // cout << "i2 = " << i << endl;
                break;
            }
        }
        cout << ans << endl;
    }
}