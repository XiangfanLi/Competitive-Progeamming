#include <bits/stdc++.h>


using namespace std;

const int MAXN = 300010;

int t, n;
vector<int> neighs[MAXN];

int dep_max_dist[MAXN];

int dfs(int u, int p, int dep) {
    vector<int> sons;
    for (int v: neighs[u]) {
        if (v == p)
            continue;
        sons.push_back(dfs(v, u, dep+1));
    }
    if (sons.empty()) {
        dep_max_dist[dep] = 0;
        return 0;
    } else if ((int)sons.size() == 1) {
        dep_max_dist[dep] = max(dep_max_dist[dep], sons[0] + 1);
    } else {
        sort(sons.begin(), sons.end(), greater<int>());
        dep_max_dist[dep+1+sons[1]] = max(dep_max_dist[dep+1+sons[1]], 2 + sons[0] + sons[1]);
    }
    // cout << "dfs(" << u << ") = " << sons[0] + 1 << endl;
    return sons[0] + 1;
}

bool Can(int x, int ans) {
    int dist = dep_max_dist[ans+1];
    if (dist == -1)
        return true;
    int r = (dist + 1) / 2;
    return (r + x) <= ans;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            neighs[i].clear();
        }
        int u, v;
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            neighs[u].push_back(v);
            neighs[v].push_back(u);
        }
        for (int i = 0; i <= n; ++i) {
            dep_max_dist[i] = -1;
        }
        dfs(1, 0 ,0);
        for (int i = n - 1; i >= 0; --i) {
            dep_max_dist[i] = max(dep_max_dist[i], dep_max_dist[i+1]);
        }
        // for (int i = 0; i < n; ++i) {
        //     cout << "dep_max_dist[" << i << "] = " << dep_max_dist[i] << endl;
        // }
        for (int x = 1; x <= n; ++x) {
            int low = 1;
            int high = n - 1;
            while (low < high) {
                int mid = (low + high) >> 1;
                if (Can(x, mid)) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            cout << low << " ";
        }
        cout << endl;
    }

}