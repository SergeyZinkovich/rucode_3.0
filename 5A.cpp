#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>

using namespace std;

int n, m;
vector<int> p;

int get(int i) {
    return (i == p[i]) ? i : (p[i] = get(p[i]));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    vector<pair<int, pair<int, int>>> g;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g.push_back({c, {a, b}});
    }

    int cost = 0;
    vector<pair<int, int>> res;

    sort(g.begin(), g.end());
    p.resize(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++) {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (get(a) != get(b)) {
            cost += l;
            res.push_back (g[i].second);
            a = get(a);
            b = get(b);
            if (rand() & 1)
                swap (a, b);
            if (a != b)
                p[a] = b;
        }
    }

    cout << cost;
    return 0;
}