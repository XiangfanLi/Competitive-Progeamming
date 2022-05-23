#include <bits/stdc++.h>


using namespace std;

int T, N, M;
int A, B;

int ans[60][60];

int main()
{
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> N >> M >> A >> B;
        int step = N + M - 1;
        memset(ans, 0, sizeof(ans));
        if(A < step || B < step) {
            cout << "Case #" << t << ": Impossible" << endl;
            continue;
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j)
                ans[i][j] = 1;
        }
        cout << "Case #" << t << ": Possible" << endl;
        ans[0][0] = A - step + 1;
        ans[0][M-1] = B - step + 1;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }

}
