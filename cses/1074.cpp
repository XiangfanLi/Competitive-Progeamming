#include <bits/stdc++.h>


using namespace std;


const int MAXN = 200010;

int n;


#define ll long long
ll p[MAXN];


int main() {
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; ++i)
        cin >> p[i], sum += p[i];
    sort(p+1, p+n+1);
    ll pre = 0;
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, (i - 1) * p[i] - pre + sum - (pre + p[i]) - (n - i) * p[i]);
        pre += p[i];
    }
    cout << ans;

}
