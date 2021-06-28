#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

string s;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cout.setf(ios::fixed);
//    cout.precision(10);

    long long mod = 1e9+7;
    cin >> s;

    vector<vector<int>> d(s.size(), vector<int>(s.size()));
    d[0][0] = 1;
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (j == s.size() - 1) {
                d[i][j] = d[i-1][j-1];
            } else if (j == 0) {
                d[i][j] = d[i-1][j+1];
            } else {
                d[i][j] = d[i-1][j+1] + d[i-1][j-1];
            }
            d[i][j] %= mod;
        }
    }

    long long numOfPermutation = 0;
    int bal = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            numOfPermutation += d[s.size() - i - 1][bal + 1];
            numOfPermutation %= mod;
            bal--;
        } else {
            bal++;
        }
    }

    cout << (numOfPermutation + 1) % mod;

    return 0;
}