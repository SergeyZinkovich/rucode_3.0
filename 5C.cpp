#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <cfloat>

using namespace std;

vector<pair<short, short>> coords;

double distance(int a, int b) {
    return sqrt(pow((coords[b].first - coords[a].first), 2) + pow((coords[b].second - coords[a].second), 2));
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    cin >> n;
    coords.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }

    const double INF = DBL_MAX;

    double ans = 0;
    vector<bool> used(n);
    vector<double> min_cost(n, INF), min_to(n, -1);
    min_cost[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || min_cost[j] < min_cost[v]))
                v = j;

        used[v] = true;
        if (min_to[v] != -1) {
            ans += min_cost[v];
        }

        for (int to = 0; to < n; to++)
            if (distance(v, to) < min_cost[to]) {
                min_cost[to] = distance(v, to);
                min_to[to] = v;
            }
    }

    cout << ans;

    return 0;
}