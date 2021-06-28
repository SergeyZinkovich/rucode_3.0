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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= -1;
    }

    const long long INF = 1e15;

    vector<long long> d(n+1, INF);
    vector<long long> p(n+1, -1);
    vector<long long> id(n+1, -1);
    d[0] = -INF;

    for (int i=0; i<n; i++) {
        int j = int (upper_bound(d.begin(), d.end(), a[i]) - d.begin());
        if (d[j-1] <= a[i] && a[i] <= d[j]) {
            d[j] = a[i];
            id[j] = i;
            p[i] = id[j-1];
        }
    }

    int pos = -1;
    for (int i = n; i >= 0; i--) {
        if (d[i] < INF) {
            pos = i;
            break;
        }
    }

    cout << pos << endl;

    vector<long long> ans;

    pos = id[pos];
    while (true) {
        ans.push_back(pos + 1);
        pos = p[pos];
        if (pos == -1) {
            break;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }


    return 0;
}