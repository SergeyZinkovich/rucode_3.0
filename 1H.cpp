#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cout.setf(ios::fixed);
//    cout.precision(10);

    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> a(n-1);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n-1; i++) {
        cin >> a[i];
    }

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        t[i] = i;
    }

    int ans = 0;

    do {
        bool b = true;
        for (int i = 0; i < n-1; i++) {
            if (p[t[i]] + p[t[i+1]] > a[i]) {
                b = false;
            }
        }
        if (b) {
            ans++;
        }
    } while (next_permutation(t.begin(), t.end()));

    cout << ans;

    return 0;
}