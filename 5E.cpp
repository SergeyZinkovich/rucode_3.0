#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <climits>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<long long>> g(n+1, vector<long long>(n+1));
    vector<pair<long long, long long>> coords(n);
    vector<long long> c(n);
    vector<long long> k(n);
    for(int i = 0; i < n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        g[i][n] = g[n][i] = c[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            g[i][j] = (abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second)) * (k[i] + k[j]);
        }
    }
    n++;

    const long long INF = LLONG_MAX;

    unsigned long long ans = 0;
    vector<bool> used(n);
    vector<long long> min_cost(n, INF), min_to(n, -1);
    vector<pair<long long, long long>> roads;
    vector<long long> towns;
    min_cost[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || min_cost[j] < min_cost[v]))
                v = j;

        used[v] = true;
        if (min_to[v] != -1) {
            if (v != n-1 && min_to[v] != n-1)
                roads.emplace_back(v, min_to[v]);
            else
                towns.push_back(v == n-1 ? min_to[v] : v);
            ans += min_cost[v];
        }

        for (int to = 0; to < n; to++)
            if (g[v][to] < min_cost[to]) {
                min_cost[to] = g[v][to];
                min_to[to] = v;
            }
    }

    cout << ans;
    cout << '\n';
    cout << towns.size();
    if (!towns.empty())
        cout << '\n';
    for (int town : towns) {
        cout << town+1 << " ";
    }
    cout << '\n';
    cout << roads.size();
    if (!roads.empty())
        cout << '\n';
    for (pair<int, int> road : roads) {
        cout << road.first+1 << " " << road.second+1 << '\n';
    }
    return 0;
}