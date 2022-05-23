#include <bits/stdc++.h>


using namespace std;

int n, m;

char mp[1010][1010];

void dfs(int i, int j) {
    if (mp[i][j] == '.')
        mp[i][j] = 'V';
    else
        return;
    if (i - 1 >= 0)
        dfs(i - 1, j);
    if (i + 1 < n)
        dfs(i + 1, j);
    if (j - 1 >= 0)
        dfs(i, j - 1);
    if (j + 1 < m)
        dfs(i, j + 1);
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        cin >> mp[i][j];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        if (mp[i][j] == '.') 
            ++ans, dfs(i, j);
    }
    cout << ans;
}
