#include <bits/stdc++.h>


using namespace std;

void dfs(string S, int i, string n1, string n2, int& ans) {
    if (i >= (int)S.size()) {
        sort(n1.begin(), n1.end(), [&](char a, char b) {
            return a > b;
        });
        sort(n2.begin(), n2.end(), [&](char a, char b) {
            return a > b;
        });
        if (!(n1.empty() || n1[0] == '0') && !(n2.empty() || n2[0] == '0'))
        {
            ans = max(ans, std::atoi(n1.c_str()) * std::atoi(n2.c_str()));
        }
        return;
    }
    char c = S[i];
    dfs(S, i+1, S.substr(i, 1) + n1, n2, ans);
    dfs(S, i+1, n1, S.substr(i, 1) + n2, ans);
    dfs(S, i+1, n1 + c, n2, ans);
    dfs(S, i+1, n1, n2 + c, ans);
}

int main() {
    string N;
    cin >> N;
    string n1 = "", n2 = "";
    int ans = 0;
    dfs(N, 0, n1, n2, ans);
    cout << ans << endl;
}