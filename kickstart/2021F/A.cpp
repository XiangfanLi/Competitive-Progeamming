#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 500010;
int T, N;
string bin;
int dist[MAXN];
#define ll long long

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        cin >> bin;
        for (int i = 0; i < N; ++i) {
            dist[i] = N;
        }
        int left = -1;
        for (int i = 0; i < N; ++i) {
            if(bin[i] == '1') {
                dist[i] = 0;
                left = i;
            } else if(left != -1) {
                dist[i] = min(dist[i], i - left);
            }
        }
        int right = -1;
        for (int i = N-1; i >= 0; --i) {
            if(bin[i] == '1') {
                right = i;
            } else if(right != -1) {
                dist[i] = min(dist[i], right - i);
            }
        }
        ll ans = 0;
        for(int i = 0; i < N; ++i)
            ans += dist[i];
        cout << "Case #" << t << ": " << ans << endl;
    }


}