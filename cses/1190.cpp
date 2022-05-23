#include <bits/stdc++.h>


using namespace std;

#define ll long long

const int MAXN = 200010;
int n, m;
ll x[MAXN];

ll tree_l[MAXN*4];
ll tree_r[MAXN*4];
ll tree[MAXN*4];
ll tree_sum[MAXN*4];

void build(int pos, int l, int r) {
    if (l == r) {
        tree_sum[pos] = tree[pos] = tree_l[pos] = tree_r[pos] = x[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2*pos, l, mid);
    build(2*pos+1, mid+1, r);
    tree[pos] = max(max(tree_r[2*pos], 0LL) + max(tree_l[2*pos+1], 0LL), 
    max(tree[2*pos], tree[2*pos+1]));
    tree_l[pos] = max(tree_sum[2*pos] + max(0LL, tree_l[2*pos+1]), tree_l[2*pos]);
    tree_r[pos] = max(tree_sum[2*pos+1] + max(0LL, tree_r[2*pos]), tree_r[2*pos+1]);
    tree_sum[pos] = tree_sum[2*pos] + tree_sum[2*pos+1];
    return;
}

void modify(int k, int val, int pos, int l, int r) {
    if (l == r) {
        x[l] = val;
        tree[pos] = tree_l[pos] = tree_r[pos] = val;
        tree_sum[pos] = val;
        return;
    } 
    int mid = (l + r) >> 1;
    if (k <= mid) {
        modify(k, val, 2*pos, l, mid);
    } else {
        modify(k, val, 2*pos+1, mid+1, r);
    }
    tree[pos] = max(max(tree_r[2*pos], 0LL) + max(tree_l[2*pos+1], 0LL), 
    max(tree[2*pos], tree[2*pos+1]));
    tree_l[pos] = max(tree_sum[2*pos] + max(0LL, tree_l[2*pos+1]), tree_l[2*pos]);
    tree_r[pos] = max(tree_sum[2*pos+1] + max(0LL, tree_r[2*pos]), tree_r[2*pos+1]);
    tree_sum[pos] = tree_sum[2*pos] + tree_sum[2*pos+1];
    return;
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int k, val;
        cin >> k >> val;
        modify(k, val, 1, 1, n);
        cout << tree[1] << endl;
    }
}