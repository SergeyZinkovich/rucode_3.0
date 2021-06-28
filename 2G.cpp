#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cout.setf(ios::fixed);
//    cout.precision(10);

    long long mod = 1e9+7;
    int n, k;
    cin >> n >> k;

    vector<int> d(n+1);
    d[0] = 1;
    d[1] = 2;
    for (int i = 2; i < n+1; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i > 0 && ans[i-1] == 1) {
            continue;
        }

        if (k < d[n - i - 1]) {
            ans[i] = 0;
            continue;
        } else {
            k -= d[n - i - 1];
            ans[i] = 1;
        }
    }

    for (int i: ans) {
        cout << i;
    }

    return 0;
}