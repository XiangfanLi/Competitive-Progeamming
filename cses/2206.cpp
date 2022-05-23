#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;

int p[MAXN];
int n, q;

int tree_l[MAXN*4];
int tree_r[MAXN*4];

void build(int pos, int l, int r) {
    if (l == r) {
        tree_l[pos] = p[l] + l;
        tree_r[pos] = p[l] + (n - l);
        return; 
    }
    int mid = (l + r) >> 1;
    build(2 * pos, l, mid);
    build(2 * pos + 1, mid+1, r);
    tree_l[pos] = min(tree_l[2*pos], tree_l[2*pos+1]);
    tree_r[pos] = min(tree_r[2*pos], tree_r[2*pos+1]);
}

void modify(int pos, int l, int r, int k, int x) {
    if (k < l || k > r)
        return;
    if (l == r) {
        tree_l[pos] = x + l;
        tree_r[pos] = x + (n - l);
        return; 
    }
    int mid = (l + r) >> 1;
    modify(2*pos, l, mid, k, x);
    modify(2*pos+1, mid+1, r, k, x);
    tree_l[pos] = min(tree_l[2*pos], tree_l[2*pos+1]);
    tree_r[pos] = min(tree_r[2*pos], tree_r[2*pos+1]);
    return;
}

void query(int pos, int l, int r, int s, int e, bool is_left, int& ans) {
    if (e < l || s > r) {
        return;
    }
    if (l >= s && r <= e) {
        ans = min(ans, is_left ? tree_l[pos] : tree_r[pos]);
        return;
    }
    int mid = (l + r) >> 1;
    query(2 * pos, l, mid, s, e, is_left, ans);
    query(2 * pos + 1, mid+1, r, s, e, is_left, ans);
    return;
}


int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    int cmd;
    build(1, 1, n);
    for(int i = 1; i <= q; ++i) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            int k, x;
            scanf("%d %d", &k, &x);
            modify(1, 1, n, k, x);
        } else {
            int k;
            scanf("%d", &k);
            int ans1 = INT_MAX, ans2 = INT_MAX;
            query(1, 1, n, 1, k, false, ans1);
            query(1, 1, n, k, n, true, ans2);
            // cout << "ans1 = " << ans1 << ", ans2 = " << ans2 << endl;
            ans1 -= (n - k);
            ans2 -= k;
            cout << min(ans1, ans2) << endl;
        }
    } 
}