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

    set<int> s;
    for (int i = 1; i < 105000; i++) {
        s.insert(i);
    }

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a > 0) {
            auto f = s.lower_bound(a);
            cout << *f << endl;
            s.erase(f);
        } else {
            s.insert(abs(a));
        }
    }



    return 0;
}