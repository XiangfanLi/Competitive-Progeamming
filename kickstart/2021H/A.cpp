#include <bits/stdc++.h>

using namespace std;

int T;
string S, F;

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> S;
        cin >> F;
        int ans = 0;
        for (int i = 0; i < (int)S.size(); ++i) {
            int Min = 26;
            for (char c: F) {
                int high = max((int)S[i], (int)c);
                int low = min((int)S[i], (int)c);
                Min = min(Min, min(high - low, (26 - (high - low))));
            }
            ans += Min;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}