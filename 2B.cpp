#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

int n;

void rec(string sec, int bal, int k) {
    if (bal < 0 || bal > 2 * n - k) {
        return;
    }

    if (2 * n == k) {
        cout << sec << '\n';
    }

    rec(sec + '(', bal + 1, k + 1);
    rec(sec + ')', bal - 1, k + 1);
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

    rec("", 0, 0);

    return 0;
}