#include <bits/stdc++.h>


using namespace std;
#define MAXN 800010
int T, N;
int A, B;
vector<int> neighs[MAXN];
int F[MAXN];
map<int, int> total_cnt;

void get_total(int u, int p) {
    total_cnt[F[u]]++;
    for (int v: neighs[u]) {
        if (v != p)
            get_total(v, u);
    }
    return;
}

int ans;
int dfs(int u, int p, map<int, int>& cnts) {
    int ret = 0;
    bool first = true;
    for (int v: neighs[u]) {
        if (v != p) {
            map<int, int> cnts2;
            int sub = dfs(v, u, first ? cnts : cnts2);
            if (first) {
                ret = sub;
                first = false;
            } else {
            
                for (auto iter: cnts2) {
                    int ttc = total_cnt[iter.first];
                    if (cnts.count(iter.first) == 0) {
                        if (iter.second < ttc)
                            ++ret;
                    } else {
                        if (cnts[iter.first] + iter.second == ttc) {
                            --ret;
                        }
                    }
                    cnts[iter.first] += iter.second;
                }
            }
        }
    }
    cnts[F[u]]++;
    if (cnts[F[u]] == 1 && cnts[F[u]] < total_cnt[F[u]]) {
        ++ret;
    }
    if (cnts[F[u]] != 1 && cnts[F[u]] == total_cnt[F[u]]) {
        --ret;
    }
    if (ret == 0 && u != 1) {
        ++ans;
    }
    return ret;
}


int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        total_cnt.clear();
        for (int i = 1; i <= N; ++i) {
            neighs[i].clear();
        }
        for (int i = 1; i <= N - 1; ++i)
        {
            cin >> A >> B;
            neighs[A].push_back(B);
            neighs[B].push_back(A);
        }
        for (int i = 1; i <= N; ++i) {
            cin >> F[i];
        }
        get_total(1, 0);
        ans = 0;
        map<int, int> cnts;
        dfs(1, 0, cnts);
        cout << "Case #" << t << ": " << ans << endl;

    }

}