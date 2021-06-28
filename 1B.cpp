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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> s;

    for (int i = 0; i < k; i++) {
        s.insert(a[i]);
    }
    cout<< *s.begin() << endl;

    for (int i = k; i < n; i++) {
        s.erase(s.find(a[i-k]));
        s.insert(a[i]);
        cout<< *s.begin() << endl;
    }

    return 0;
}