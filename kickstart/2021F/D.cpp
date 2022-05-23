#include <bits/stdc++.h>

using namespace std;
#define ll long long
int T, N, M;
ll K;
ll L[20], R[20], A[20];
vector<int> neigh[20];
int X, Y;
ll mem[50000];

ll ways(int key, ll sum) {
    if (mem[key] != -1)
        return mem[key];
    if (sum == K)
        return 1;
    ll ret = 0;
    vector<bool> visited(N, false);
    for (int u = 0; u < N; ++u) {
        if ((1 << u) & key) {
            for (int v: neigh[u]) {
                if (!visited[v] && (!((1 << v) & key)) && sum >= L[v] && sum <= R[v]) {
                    ret += ways(key | (1 << v), sum + A[v]);
                    visited[v] = true;
                }
            }
        }
    }
    mem[key] = ret;
    return ret;
}


int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; ++i) {
            cin >> L[i] >> R[i] >> A[i];
            neigh[i].clear();
        }
        for (int i = 0; i < M; ++i) {
            cin >> X >> Y;
            neigh[X].push_back(Y);
            neigh[Y].push_back(X);   
        }
        for (int i = 0; i < (1 << N); ++i) {
            mem[i] = -1;
        }
        ll ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += ways(1 << i, A[i]);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }

}