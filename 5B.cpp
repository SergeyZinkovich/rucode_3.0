#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> g(n+1, vector<int>(n+1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        g[n][i] = t;
        g[i][n] = t;
    }
    n++;

    const int INF = 1000000000;

    long long ans = 0;
    vector<bool> used(n);
    vector<int> min_cost(n, INF), min_to(n, -1);
    min_cost[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || min_cost[j] < min_cost[v]))
                v = j;

        used[v] = true;
        ans += min_cost[v];

        for (int to = 0; to < n; to++)
            if (g[v][to] < min_cost[to]) {
                min_cost[to] = g[v][to];
                min_to[to] = v;
            }
    }

    cout << ans;
    return 0;
}