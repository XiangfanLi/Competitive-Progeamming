#include <bits/stdc++.h>

#define ll long long
#define MAXN 300010 
using namespace std;
int T;
int D, N, K;
int h[MAXN];
int s[MAXN];
int e[MAXN];
bool in[MAXN];
bool chose[MAXN];


int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> D >> N >> K;
        for (int i = 1; i <= N; ++i) {
            cin >> h[i] >> s[i] >> e[i];
            in[i] = false;
            chose[i] = false;
        }

        priority_queue<pair<int, int> > q1;
        priority_queue<pair<int, int> > q2;

        vector<pair<int, int> > sts;
        vector<pair<int, int> > eds;
        sts.reserve(N);
        eds.reserve(N);
        for(int i = 1; i <= N; ++i) {
            sts.push_back(make_pair(s[i], i));
            eds.push_back(make_pair(e[i], i));
        }
        sort(sts.begin(), sts.end());
        sort(eds.begin(), eds.end());
        int si = 0, ei = 0;
        int n_chose = 0;
        ll ans = 0;
        ll curr = 0;
        for(int d = 1; d <= D; ++d) {
            while(ei < N && eds[ei].first < d) {
                int i = eds[ei].second;
                in[i] = false;
                if (chose[i]) {
                    --n_chose;
                    curr -= h[i];
                    chose[i] = false;
                }
                ei++;
            }
            while(si < N && sts[si].first <= d) {
                int i  = sts[si].second;
                in[i] = true;
                q2.push(make_pair(h[i], i));
                //cout << "push into q2" << endl;
                ++si;
            }
            while(n_chose < K) {
                //cout << "while 1" << endl;
                while(!q2.empty() && !in[q2.top().second]) {
                    //cout << "!in" << endl;
                    q2.pop();
                }
                if (q2.empty())
                    break;
                else {
                    auto p = q2.top();
                    q2.pop();
                    chose[p.second] = true;
                    curr += h[p.second];
                    n_chose++;
                    //cout << "push into q1, curr = " << curr  << endl;
                    q1.push(make_pair(-p.first, p.second));
                }
            }
            while(n_chose == K ) {
                while(!q2.empty() && !in[q2.top().second]) {
                    //cout << "!in" << endl;
                    q2.pop();
                }
                while(!q1.empty() && !in[q1.top().second]) {
                    //cout << "!in" << endl;
                    q1.pop();
                }
                if (q1.empty() || q2.empty() || -q1.top().first >= q2.top().first) {
                    break;
                }
                //cout << "while 2" << endl;
                auto p1 = q1.top();
                auto p2 = q2.top();
                q1.pop();
                q2.pop();
                curr -= -p1.first;
                curr += p2.first;
                chose[p1.second] = false;
                chose[p2.second] = true; 
                q1.push(make_pair(-p2.first, p2.second));
                q2.push(make_pair(-p1.first, p1.second));
            }
            ans = max(ans, curr);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}