#include <bits/stdc++.h>


using namespace std;

int T;
string S;

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Hello World" << endl;
        cin >> S;
        int N = (int)S.size();
        vector<int> cnt(26, 0);
        string ans = S;
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (S[i] == ans[i]) {
                bool found = false;
                for (int j = 0; j < N; ++j) {
                    if (i == j)
                        continue;
                    if (ans[j] != ans[i] && S[j] != ans[i]) {
                        swap(ans[i], ans[j]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ok = false;
                    break;
                }
            }
        }
        
        cout << "Case #" << t << ": " << (ok ? ans :"IMPOSSIBLE") << endl;
    }

}