#include <bits/stdc++.h>


using namespace std;


const int MAXN = 200010;
int t, n, k;

int a[MAXN];

int C[MAXN];

vector<int> idxs[MAXN];

int lowbit(int x) {
    return x & (-x);
}

int Sum(int i) {
    int res = 0;
    while (i != 0) {
        res += C[i];
        i -= lowbit(i);
    }
    return res;
}

void Update(int i, int k) {
    while (i <= n) {
        C[i] += k;
        i += lowbit(i);
    }
    return;
}


pair<bool, pair<int, int> > Can(int range) {
    int x = 1;
    int y = 1 + range;
    for (int i = 1; i <= n; ++i) {
        C[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x && a[i] <= y) {
            Update(i, 1);
        } else {
            Update(i, -1);
        }
    }
    for (; y <= n;) {
        if (Sum(n) >= k) {
            return make_pair(true, make_pair(x, y));
        }
        for (int i: idxs[x]) {
            Update(i, -2);
        }
        ++x, ++y;
        for (int i: idxs[y]) {
            Update(i, 2);
        }
    }
    return make_pair(false, make_pair(-1, -1));
}

vector<pair<int, int> > Calc(int x, int y) {
    auto p = Can(y - x);
    int last = 0;
    int last_i = 0;
    vector<pair<int ,int> > ans;
    int kk = 0;
    for (int i = 1; i <= n && kk < k - 1; ++i) {
        int su = Sum(i);
        if (su > last) {
            ++kk;
            ans.push_back(make_pair(last_i + 1, i));
            last = su;
            last_i = i;
        }
    }
    ans.push_back(make_pair(last_i + 1, n));
    return ans;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            idxs[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            idxs[a[i]].push_back(i);
        }

        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = (low + high) >> 1;
            auto p = Can(mid);
            if (p.first) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        auto p = Can(low);
        auto ans = Calc(p.second.first, p.second.second);
        cout << p.second.first << " " << p.second.second << endl;
        for (auto& seg : ans) {
            cout << seg.first << " " << seg.second << endl;
        }


    }
}