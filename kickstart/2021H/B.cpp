#include <bits/stdc++.h>


using namespace std;

unordered_map<char, int> Map = 
{ {'U', 0},
  {'R', 1},
  {'Y', 2},
  {'B', 4},
  {'O', 3},
  {'P', 5},
  {'G', 6},
  {'A', 7}
};
int T;
int N;
string P;

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        cin >> P;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int key = Map[P[i]];
            int pre_key = (i == 0) ? 0 : Map[P[i-1]]; 
            for (int k = 0; k < 3; ++k) {
                if ((key & (1 << k))
                    && !(pre_key & (1 << k)))
                    ++ans;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}