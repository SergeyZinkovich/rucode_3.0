#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <climits>

using namespace std;

int n, m, k;
vector<int> p, size_;

int get(int i) {
    return (i == p[i]) ? i : (p[i] = get(p[i]));
}

void unite (int a, int b) {
    a = get (a);
    b = get (b);
    if (a == b)
        return;
    if (size_[a] > size_[b])
        swap (a, b);
    p[a] = b;
    size_[b] += size_[a];
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

    }

    p.resize(n);
    size_.resize(n, 1);
    for (int i = 0; i < n; i++)
        p[i] = i;

    vector<pair<string, pair<int, int>>> v;
    for (int i = 0; i < k; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        a--;
        b--;

        v.push_back({s, {a, b}});
    }

    vector<string> ans;
    for (int i = k-1; i >= 0; i--) {
        if (v[i].first == "ask") {
            if (get(v[i].second.first) == get(v[i].second.second))
                ans.emplace_back("YES");
            else
                ans.emplace_back("NO");
        } else {
            unite(v[i].second.first, v[i].second.second);
        }
    }

    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << '\n';
    }

    return 0;
}