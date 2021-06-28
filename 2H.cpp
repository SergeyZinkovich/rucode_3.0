#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector<vector<int>> cc;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cout.setf(ios::fixed);
//    cout.precision(10);

    int n, k, p;
    cin >> n >> k >> p;

    cc.resize(n, vector<int>(k+1));
    cc[0][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (j == 0 ) {
                cc[i][j] = 1;
                continue;
            }
            if (j == 1 ) {
                cc[i][j] = i;
                continue;
            }
            if (j == i) {
                cc[i][j] = 1;
                continue;
            }

            cc[i][j] = cc[i-1][j-1] + cc[i-1][j];
        }
    }

    vector<int> ans(k);
    for (int i = 0; i < k; i++) {
        int border = i > 0 ? ans[i-1] + 1 : 1;
        for (int a = border; a <= n; a++) {
            int count = cc[n - a][k - i - 1];
            if (p < count) {
                ans[i] = a;
                break;
            } else {
                p -= count;
            }
        }
    }

    for (int i: ans) {
        cout << i << " ";
    }

    return 0;
}