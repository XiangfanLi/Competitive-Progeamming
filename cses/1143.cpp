#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, m;
int h[MAXN];
int r[MAXN];

int tree[4*MAXN];

void build(int pos, int l, int r) {
    if (l == r) {
        tree[pos] = h[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2*pos, l, mid);
    build(2*pos+1, mid+1, r);
    tree[pos] = max(tree[2*pos], tree[2*pos+1]);
    return;
}

int query(int pos, int l, int r, int val) {
    // cout << "Max of [" << l << ", " << r << "] = " << tree[pos] << endl;
    if (l == r) {
        return (tree[pos] >= val) ? l : 0;
    }
    int mid = (l + r) >> 1;
    if (tree[2*pos] >= val) {
        return query(2*pos, l, mid, val);
    } else {
        return query(2*pos+1, mid+1, r, val);
    }
}

void substract(int i, int pos, int l, int r, int val) {
    if (i < l || i > r)
        return;
    if (l == r) {
        tree[pos] -= val;
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid)
    {
        substract(i, 2*pos, l, mid, val);
    } else {
        substract(i, 2*pos+1, mid+1, r, val);
    }
    tree[pos] = max(tree[2*pos], tree[2*pos+1]);
    return;
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        cin >> r[i];
    }
    for (int i = 1; i <= m; ++i) {
        int j = query(1, 1, n, r[i]);
        cout << j << " ";
        if (j)
            substract(j, 1, 1, n, r[i]);
    }
    return 0;
}