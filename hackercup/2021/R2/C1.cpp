#include <bits/stdc++.h>

using namespace std;

int T, R, C, K;

int up[2000010];
int down[2000010];

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> R >> C >> K;
        char board[R+2][C+2];
        for (int i = 1; i <= R; ++i) {
            scanf("%s", &board[i][1]);
        }
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (board[i][j] == 'X') {
                    if (i < K) 
                        ++up[j];
                    else if (i > K)
                        ++down[j];
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= C; ++j) {
            if (board[K][j] == 'X')
                ++ans;
        }
        // Move Up
        vector<int> up_emptys(R+1, 0);
        for (int j = 1; j <= C; ++j)
        {
            int up_cnt = up[j];
            for (int i = K; i <= R + 1; ++i) {
                if (up_cnt >= K)
                    break;
                if (i > R || board[i][j] == '.') {
                    up_emptys[i-K]++;
                } 
                if (i <= R && board[i][j] == 'X') {
                    up_cnt++;
                }
            }
        }
        for (int i = 0; i < R; ++i) {
            ans = min(ans, i + (C - up_emptys[i]));
        }
        // Move down
        vector<int> down_emptys(R+1, 0);
        for (int j = 1; j <= C; ++j)
        {
            int down_cnt = down[j];
            for (int i = K; i >= 0; --i) {
                if (down_cnt >= R - K + 1)
                    break;
                if (i < 1 || board[i][j] == '.') {
                    down_emptys[K-i]++;
                }
                if (i >= 1 && board[i][j] == 'X') {
                    down_cnt++;
                }
            }
        }
        for (int i = 0; i < R; ++i) {
            ans = min(ans, i + (C - down_emptys[i]));
        }
        cout << "Case #" << t << ": " << ans << endl;
    }

}