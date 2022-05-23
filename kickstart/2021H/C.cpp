#include <bits/stdc++.h>

using namespace std;

int T, N;

#define MAXN 500010
char str[MAXN];
int pre[MAXN];
int nxt[MAXN];
set<int> idxs[10];

bool is_pair(char a, char b) {
    return ((a - '0' + 1) % 10 == (b - '0'));
}

bool reduce(int k) {
    bool change = false;
    for (int i: idxs[k]) {
        if (nxt[nxt[i]] != -1) {
            if(is_pair(str[nxt[i]], str[nxt[nxt[i]]])) {
                idxs[str[nxt[i]] - '0'].erase(nxt[i]);
            }
        }
        if (pre[i] != -1) {
            if (is_pair(str[pre[i]], str[i])) {
                idxs[str[pre[i]] - '0'].erase(pre[i]);
            }
        }
        str[i] = '0' + (k + 2) % 10;
        nxt[i] = nxt[nxt[i]];

        if (nxt[i] != -1) {
            pre[nxt[i]] = i;
        }
        if (pre[i] != -1 && is_pair(str[pre[i]], str[i])) {
            idxs[str[pre[i]] - '0'].insert(pre[i]);
        }
        if (nxt[i] != -1 && is_pair(str[i], str[nxt[i]])) {
            idxs[str[i] - '0'].insert(i);
        }
        change = true;
    }
    idxs[k].clear();
    return change;
}

bool iteration() {
    bool change = false;
    for (int k = 0; k < 10; ++k) {
        if (reduce(k))
            change = true;
    }
    return change;
}


int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        scanf("%s", str);
        for (int i = 0; i < N - 1; ++i)
            nxt[i] = i + 1;
        nxt[N-1] = -1;
        for (int i = N - 1; i >= 0; --i)
            pre[i] = i - 1;
        for (int k = 0; k < 10; ++k) {
            idxs[k].clear();
        }       
        for (int i = 0; i < N - 1; ++i) {
            if ((str[i] - '0' + 1) % 10 == str[i+1] - '0') {
                idxs[str[i] - '0'].insert(i);
            }
        }
        while(iteration());
        int i = 0;
        cout << "Case #" << t << ": ";
        while(i != -1)
        {
            cout << str[i];
            i = nxt[i];
        }
        cout << endl;
    }
}