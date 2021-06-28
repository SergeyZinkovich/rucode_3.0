#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

int n;

void rec(string ans, int val, int m) {
    if (val == 0) {
        cout << ans << '\n';
    }

    int border = min(val, m);
    for (int i = 1; i <= border; i++) {
        rec(ans + to_string(i) + " ", val - i, min(m, i));
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cout.setf(ios::fixed);
//    cout.precision(10);

    cin >> n;

    rec("", n, n);

    return 0;
}