#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
int n, m, q;

int C[MAXN];
vector<int> neigh[MAXN];
vector<int> peps[MAXN];
int dp1[MAXN][20];
vector<int> dp[MAXN][20];
int dep[MAXN];

map<pair<int, int>, set<int>> cache;
void Merge(const vector<int>& src1,
        const vector<int>& src2,
        vector<int>& dst) {

    int i1 = 0, i2 = 0;
    vector<int> dst_copy;
    while(dst_copy.size() < 10 && i1 < (int)src1.size() && i2 < (int)src2.size()) {
        if (src1[i1] < src2[i2]) {
            dst_copy.push_back(src1[i1++]);
        } else if (src1[i1] > src2[i2]) {
            dst_copy.push_back(src2[i2++]);
        } else {
            dst_copy.push_back(src1[i1++]);
            ++i2;
        }
    }
    while(dst_copy.size() < 10 && i1 < (int)src1.size()) {
        dst_copy.push_back(src1[i1++]);
    }
    while(dst_copy.size() < 10 && i2 < (int)src2.size()) {
        dst_copy.push_back(src2[i2++]);
    }
    dst = move(dst_copy);
    return;
}

int Get1(int u, int x) {
    if (x == 0) {
        return u;
    }
    int curr = u;
    int mask = 1 << 17;
    for (int k = 17; k >= 0; --k) {
        if (x & mask) {
            curr = dp1[curr][k];
            if (curr == 0)
                return 0;
        }
        mask >>= 1;
    }
    return curr;
}

vector<int> Get(int u, int x) {
    if (x == 0) {
        return peps[u];
    }
    int curr = u;
    vector<int> ret;
    int mask = 1 << 17;
    for (int k = 17; k >= 0; --k) {
        if (x & mask) {
            Merge(dp[curr][k], ret, ret);
            curr = dp1[curr][k];
        }
        mask >>= 1;
    }
    return move(ret);
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    u = Get1(u, dep[u] - dep[v]);
    if (u == v) {
        return u;
    }
    for (int k = 17; k >= 0; --k) {
        if (dp1[u][k] && dp1[u][k] != dp1[v][k]) {
            u = dp1[u][k];
            v = dp1[v][k];
        }
    }
    return dp1[u][0];
}

void dfs(int u, int p, int depth) {
    dep[u] = depth;
    if (u != 1) {
        dp1[u][0] = p;
        for (int k = 1; k < 18; ++k) {
            dp1[u][k] = dp1[dp1[u][k-1]][k-1];
        }
        Merge(peps[u], peps[p], dp[u][0]);
        for (int k = 1; k < 18; ++k) {
            if (dp1[u][k-1] && dp1[dp1[u][k-1]][k-1]) {
                Merge(dp[u][k-1], dp[dp1[u][k-1]][k-1], dp[u][k]);
            }
        }
    }

    for (int v: neigh[u]) {
        if (v != p)
            dfs(v, u, depth+1);
    }
    return;
}


int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &C[i]);
        peps[C[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        sort(peps[i].begin(), peps[i].end());
        while(peps[i].size() > 10)
            peps[i].pop_back();
    }
    dfs(1, 0, 0);
    for (int qq = 1; qq <= q; ++qq) {
        int u, v, a;
        scanf("%d %d %d", &u, &v, &a);
        int lca = LCA(u, v);
        int du = dep[u] - dep[lca];
        int dv = dep[v] - dep[lca];
        vector<int> ans;

        vector<int> set_u = Get(u, du);
        vector<int> set_v = Get(v, dv);
        Merge(set_u, set_v, ans);
        int k = min((int)ans.size(), a);
        printf("%d ", k);
        int cnt = 0;
        for(auto iter = ans.begin(); iter != ans.end(); ++iter) {
            if (++cnt > k)
                break;
            printf("%d ", *iter);
        }
        printf("\n");
    }
}