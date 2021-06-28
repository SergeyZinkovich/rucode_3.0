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

    int n, k;
    cin >> n >> k;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        t[i] = i;
    }

    do {
        bool b = true;
        for (int i = 0; i < n-1; i++) {
            if (abs(t[i+1] - t[i]) < k) {
                b = false;
            }
        }
        if (b) {
            for (int i: t) {
                cout << i + 1 << ' ';
            }
            cout << "\n";
        }
    } while (next_permutation(t.begin(), t.end()));

    return 0;
}