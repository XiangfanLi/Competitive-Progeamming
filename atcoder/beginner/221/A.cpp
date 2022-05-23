#include <bits/stdc++.h>


using namespace std;
int A, B;

int main() {
    cin >> A >> B;
    long long ans = 1;
    while(A > B) {
        A--;
        ans *= 32;
    }
    cout << ans << endl;
}