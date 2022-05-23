#include <bits/stdc++.h>

using namespace std;

int x[7], y[7];

int main() {
    cin >> x[1] >> y[1] >> x[2] >> y[2];
    cin >> x[3] >> y[3] >> x[4] >> y[4];
    cin >> x[5] >> y[5] >> x[6] >> y[6];

    for (int i = x[1]; i < x[2]; ++i) {
        double xx = i + 0.5;
        double yy = y[1];
        bool in_black = 
        (xx >= x[3] && xx <= x[4] && yy >= y[3] && yy <= y[4]) ||
        (xx >= x[5] && xx <= x[6] && yy >= y[5] && yy <= y[6]);
        if (!in_black) {
            cout << "YES" << endl;
            return 0;
        }
    }

    for (int i = x[1]; i < x[2]; ++i) {
        double xx = i + 0.5;
        double yy = y[2];
        bool in_black = 
        (xx >= x[3] && xx <= x[4] && yy >= y[3] && yy <= y[4]) ||
        (xx >= x[5] && xx <= x[6] && yy >= y[5] && yy <= y[6]);
        if (!in_black) {
            cout << "YES" << endl;
            return 0;
        }
    }

    for (int j = y[1]; j < y[2]; ++j) {
        double xx = x[1];
        double yy = j + 0.5;
        bool in_black = 
        (xx >= x[3] && xx <= x[4] && yy >= y[3] && yy <= y[4]) ||
        (xx >= x[5] && xx <= x[6] && yy >= y[5] && yy <= y[6]);
        if (!in_black) {
            cout << "YES" << endl;
            return 0;
        }
    }

    for (int j = y[1]; j < y[2]; ++j) {
        double xx = x[2];
        double yy = j + 0.5;
        bool in_black = 
        (xx >= x[3] && xx <= x[4] && yy >= y[3] && yy <= y[4]) ||
        (xx >= x[5] && xx <= x[6] && yy >= y[5] && yy <= y[6]);
        if (!in_black) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}