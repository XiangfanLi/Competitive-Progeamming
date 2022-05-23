#include <bits/stdc++.h>


using namespace std;

string S, T;


int main() {
    cin >> S >> T;
    vector<int> diff_idxs;
    for(int i = 0; i < (int)S.size(); ++i)
    {
        if (S[i] != T[i]) {
            diff_idxs.push_back(i);
        }
    }
    bool ok = diff_idxs.empty() || ((int)diff_idxs.size() == 2 
        && diff_idxs[0] + 1 == diff_idxs[1] S[diff_idxs[0]] == T[diff_idxs[1]] && S[diff_idxs[1]] == T[diff_idxs[0]]);
    cout << (ok ? "Yes" : "No") << endl;
}