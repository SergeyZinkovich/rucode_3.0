//Дейкстра для разреженных графов

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
const int INF = 1000000000;

int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    s--;
    f--;
    vector<vector<pair<int, int> > > g(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }

    vector<int> d(n, INF);
    d[s] = 0;
    set < pair<int,int> > q;
    q.insert ({d[s], s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (size_t j = 0; j < g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }

        }
    }

    cout << (d[f] != INF ? d[f] : -1) << endl;

}