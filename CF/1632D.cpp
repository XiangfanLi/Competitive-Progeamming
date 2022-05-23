#include <bits/stdc++.h>


using namespace std;


int n;
int a[200010];

int GCD(int x, int y) {
    if (x == y)
        return x;
    while (x != 0 && y != 0) {
        if (x > y) {
            x %= y;
        } else if(y > x) {
            y %= x;
        }
    }
    return (x > y) ? x : y;
}

int A[1000010];

int buildTree(int pos, int l, int r) {
    if (l == r) {
        A[pos] = a[l];
        return A[pos];
    } 
    int mid = (l + r) >> 1;
    int lg = buildTree(2*pos, l, mid);
    int rg = buildTree(2*pos+1, mid+1, r);
    A[pos] = GCD(lg, rg);
    return A[pos];
}

int query(int pos, int l, int r, int s, int e) {
    if (e < l || s > r) {
        return -1;
    }
    if (l >= s && r <= e) {
        return A[pos];
    }
    // if (l == r)
    //     return A[pos];
    int mid = (l + r) >> 1;
    int lg = query(2*pos, l, mid, s, e);
    int rg = query(2*pos+1, mid+1, r, s , e);
    if (lg == -1) {
        return rg;
    } else if (rg == -1) {
        return lg;
    } else {
        return GCD(lg, rg);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    buildTree(1, 1, n);
    vector<bool> changes(n + 1, false);
    for (int l = 1, r = 1; l <= n;) {
        int gcd = query(1, 1, n, l, r);
        bool found = false;
        while (r <= n) {
            gcd = GCD(gcd, a[r]);
            // cout << "GCD l = " << l << ", r = " << r << ", " << gcd << endl;
            if (gcd == r - l + 1) {
                found = true;
                break;
            } else if (gcd < r - l + 1) {
                break;
            }
            ++r;
        }
        if (r <= n) {
            // changes[r] = true;
            // l = r + 1;
            if (found) {
                changes[r] = true;
                l = r + 1;
                r = l;
            } else {
                l = l + 1;
            }
        } else {
            break;
        }
    }
    int ans2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (changes[i])
            ++ans2;
        cout << ans2 << " ";
    }
    return 0;
}