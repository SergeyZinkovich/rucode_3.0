#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

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
    vector<int> a;
    a.reserve(2*n);
    int tmp1, tmp2;
    for (int i = 0; i < n; i++) {
        cin >> tmp1 >> tmp2;
        a.push_back(tmp1);
        a.push_back(tmp2);
    }
    vector<int> b = a;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (int i = 0; i < 2*n; i++) {
        cout << lower_bound(a.begin(), a.end(), b[i]) - a.begin() << ' ';
        if (i % 2 == 1) {
            cout << endl;
        }
    }

    return 0;
}